#include "LoRaWan_APP.h"
#include "Arduino.h"

#include "config.h"

#include "packet.h"
#include "packetStore.h"
#include "btnPanel.h"

#define SYNC_TIMEOUT 5 * 60 * 1000
#define SYNC_ID 0b11111
#define TX_DLY 200
#define INIT_TIMEOUT (SYNC_ID * TX_DLY)

#define SYNC_LED 2      //0 - green, 1 - blue, 2 - orange, 3 - red
#define SYNC_DONE_LED 0 //0 - green, 1 - blue, 2 - orange, 3 - red
#define SYNC_BLINK_TIME 200

/*
 * set LoraWan_RGB to 1,the RGB active in loraWan
 * RGB red means sending;
 * RGB green means received done;
 */
//#ifndef LoraWan_RGB
#define LoraWan_RGB 0
//#endif

#define RF_FREQUENCY 868000000 // Hz

#define TX_OUTPUT_POWER 5 // dBm

#define LORA_BANDWIDTH 0 // [0: 125 kHz, \
                         //  1: 250 kHz, \
                         //  2: 500 kHz, \
                         //  3: Reserved]

#define LORA_SPREADING_FACTOR 7 // [SF7..SF12]

#define LORA_CODINGRATE 1      // [1: 4/5, \
                               //  2: 4/6, \
                               //  3: 4/7, \
                               //  4: 4/8]
#define LORA_PREAMBLE_LENGTH 8 // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT 0  // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON false
#define LORA_IQ_INVERSION_ON false

#define RX_TIMEOUT_VALUE 1000
#define BUFFER_SIZE PACKET_SIZE // Define the payload size here

uint8_t nodeId;

static RadioEvents_t RadioEvents;
void OnTxDone(void);
void OnTxTimeout(void);
void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);

typedef enum
{
    RX,
    LOWPOWER
} States_t;

int8_t txNumber;
States_t state;
bool sleepMode = false;
int16_t Rssi, rxSize, Snr;
uint32_t lastSync;

packet txPacket;

packetStore stack;

void sendPacket(packet packet);
void executeCommand(packet packet);

btnPanel panel(BTN1PIN, BTN2PIN, BTN3PIN, BTN4PIN, BTN1LED, BTN2LED, BTN3LED, BTN4LED);
bool local[N_BUTTONS] = {true, true, true, true};
uint8_t oldState = 0;

void setup()
{
    boardInitMcu();
    Serial.begin(115200);
    nodeId = SYNC_ID;
    txNumber = 1;
    Rssi = 0;

    RadioEvents.TxDone = OnTxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxDone = OnRxDone;

    Radio.Init(&RadioEvents);
    Radio.SetChannel(RF_FREQUENCY);
    Radio.SetTxConfig(MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                      LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                      LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                      true, 0, 0, LORA_IQ_INVERSION_ON, 3000);

    Radio.SetRxConfig(MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
                      LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
                      LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
                      0, true, 0, 0, LORA_IQ_INVERSION_ON, true);

    panel.begin();

    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {
        panel.ledOn(i);
        panel.refreshLeds();
        delay(100);
    }
    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {
        panel.ledToggle(i);
        panel.refreshLeds();
        delay(100);
        panel.ledToggle(i);
        panel.refreshLeds();
        delay(100);
    }

    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {
        panel.ledOff(i);
        panel.refreshLeds();
        delay(100);
    }

    panel.blinkLed(SYNC_LED, SYNC_BLINK_TIME);
    //turnOnRGB(COLOR_SEND, 0);
    packet syncPacket(0, TTL, nodeId);
    sendPacket(syncPacket);
    lastSync = millis();
}

void loop()
{
    switch (state)
    {
    case RX:
        //turnOnRGB(0, 0);
        Radio.Rx(0);

        panel.readButtons();

        if (panel.state != oldState)
        {
            Serial.print("\n\rButtons state changed, entering local buttons loop: ");
            for (uint8_t i = 0; i < N_BUTTONS; i++)
            {
                if (panel.getLedState(i) == OFF && panel.getButton(i))
                {
                    Serial.printf("Signalling request %u", i);
                    packet packet(txNumber, TTL, COMMAND, REQUEST, i);
                    sendPacket(packet);
                    panel.blinkLed(i);
                    local[i] = true;
                    continue;
                }
                if (panel.getLedState(i) == ON && panel.getButton(i))
                {
                    Serial.printf("Clearing ACK %u", i);
                    packet packet(txNumber, TTL, COMMAND, CLEAR, i);
                    sendPacket(packet);
                    panel.ledOff(i);
                    local[i] = true;
                    continue;
                }
                if (panel.getLedState(i) == BLINKING && panel.getButton(i))
                {
                    if (local[i])
                    {
                        Serial.printf("Cancelling request %u", i);
                        packet packet(txNumber, TTL, COMMAND, CANCEL, i);
                        sendPacket(packet);
                        panel.ledOff(i);
                        local[i] = true;
                    }
                    else
                    {
                        Serial.printf("Sending ACK for request %u", i);
                        packet packet(txNumber, TTL, COMMAND, ACKNOWLEDGE, i);
                        sendPacket(packet);
                        panel.ledOn(i);
                        local[i] = true;
                    }
                    continue;
                }
            }
            oldState = panel.state;
        }

        if (nodeId == SYNC_ID && millis() - lastSync > INIT_TIMEOUT)
        {
            panel.ledOff(SYNC_LED);
            Serial.printf("\n\rGot %u SYNC responses, biggest nodeID was %u\n\n", stack.getSize(), stack.getMaxSyncId());
            nodeId = stack.getMaxSyncId() + 1;

            panel.blinkLed(SYNC_DONE_LED, SYNC_BLINK_TIME);
            uint32_t now = millis();
            while (millis() - now < nodeId * 2 * SYNC_BLINK_TIME)
            {
                panel.refreshLeds();
            }
            panel.ledOff(SYNC_DONE_LED);
            stack.clear();
            lastSync = millis();
            break;
        }
        break;

    case LOWPOWER:
        //turnOnRGB(0, 0);
        lowPowerHandler();
        break;

    default:
        break;
    }

    Radio.IrqProcess();
    panel.refreshLeds();
}

void OnTxDone(void)
{
    Serial.print("\n\rTX done......");
    txNumber += 1;
    if (nodeId != SYNC_ID)
    {
        stack.push(txPacket.getStruct());
    }
    //turnOnRGB(0, 0);
    state = RX;
    Serial.print("\n\rGoing to RX!");
    Serial.printf(" - nodeId: %u", nodeId);
}

void OnTxTimeout(void)
{
    Radio.Sleep();
    Serial.printf("\n\rTX Timeout, retrying. State: %u", state);
    sendPacket(txPacket);
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
    Rssi = rssi;
    rxSize = size;
    Snr = snr;
    packet packet(payload);
    //turnOnRGB(COLOR_RECEIVED, 0);
    Radio.Sleep();

    Serial.printf("\r\nReceived packet ");
    packet.debug();
    Serial.printf("; Rssi %d, SNR %d and length %d\n\n", Rssi, Snr, rxSize);

    txNumber = packet.getId() > txNumber ? packet.getId() : txNumber;

    if (packet.getTtl() <= 0)
    {
        Serial.print("\r\nTTL timeout, ignoring.");
        return;
    }

    if (packet.getType() == SYNC)
    {
        Serial.printf("\r\nGot SYNC packet, my nodeId is %u and it's been %ums since last sync (tresh %ums)", nodeId, millis() - lastSync, INIT_TIMEOUT);
        if (nodeId == SYNC_ID && millis() - lastSync <= INIT_TIMEOUT)
        {
            Serial.print("\n\rReceived an existing ID packet.");
            stack.push(packet.getStruct());
            return;
        }

        Serial.print("\n\rI have my ID already");
        if (nodeId > packet.getArg() || packet.getArg() == SYNC_ID)
        {
            Serial.print(" and it's bigger than the one I just received so I'm sending it out.");
            packet.setSyncArg(nodeId);
        }
        else
        {
            Serial.print(" but it's lower than the one I just received so I'm just repeating that one.");
        }

        packet.setId(txNumber);
        sendPacket(packet);
        return;
    }

    if (packet.getType() == COMMAND)
    {
        if (stack.isPacketKnown(packet.getStruct()))
        {
            Serial.print("\r\nI already retransmitted this one, ignoring.");
            state = RX;
            return;
        }
        Serial.print("\r\nRetransmitting command message.");
        sendPacket(packet);
        executeCommand(packet);
        return;
    }

    Serial.print("\r\nUnknown packet type, ignoring.");
    state = RX;
    return;
}

void sendPacket(packet packet)
{
    txPacket = packet;
    if (nodeId < SYNC_ID)
    {
        uint32_t now = millis();
        while ((millis() - now) < (TX_DLY * nodeId))
        {
            panel.refreshLeds();
        }
    }
    txPacket.decreaseTtl();
    if (packet.getTtl() <= 0)
    {
        Serial.print("\r\nTTL timeout, ignoring.");
        state = RX;
        return;
    }
    //turnOnRGB(COLOR_SEND, 0);

    Serial.print("\r\nSending packet:");
    packet.debug();

    byte payload[BUFFER_SIZE];
    txPacket.getPayload(payload);
    Radio.Send(payload, sizeof(payload));
    state = LOWPOWER;
    return;
}

void executeCommand(packet packet)
{
    uint8_t input = packet.getArg();
    uint8_t command = packet.getCommand();

    Serial.printf("\n\rReceived external input %u, entering remote buttons loop: ", input);

    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {        
        if (command == REQUEST && input == i)
        {
            Serial.print("Received request ");
            Serial.print(i);
            Serial.println(".");
            panel.blinkLed(i);
            local[i] = false;
            continue;
        }
        if (command == CLEAR && input == i)
        {
            Serial.print("Received clear ACK ");
            Serial.print(i);
            Serial.println(".");
            panel.ledOff(i);
            local[i] = false;
            continue;
        }
        if (command == CANCEL && input == i)
        {
            Serial.print("Received cancellation for request ");
            Serial.print(i);
            Serial.println(".");
            panel.ledOff(i);
            local[i] = false;
            continue;
        }

        if (command == ACKNOWLEDGE && input == i)
        {
            Serial.print("Received ACK for request ");
            Serial.print(i);
            Serial.println(".");
            panel.ledOn(i);
            local[i] = false;
            continue;
        }
    }
    oldState = panel.state;
    Serial.println();
}