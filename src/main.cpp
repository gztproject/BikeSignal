#include "LoRaWan_APP.h"
#include "Arduino.h"

#include "packet.h"
#include "packetStore.h"

#define SYNC_TIMEOUT 5 * 60 * 1000
#define SYNC_ID 0b11111
#define TX_DLY 100
#define INIT_TIMEOUT (SYNC_ID * TX_DLY)

#define BTN_PIN GPIO7

/*
 * set LoraWan_RGB to 1,the RGB active in loraWan
 * RGB red means sending;
 * RGB green means received done;
 */
#ifndef LoraWan_RGB
#define LoraWan_RGB 0
#endif

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
bool newCmd;

packet txPacket;

packetStore stack;

void sendPacket(packet packet);

void setup()
{
    boardInitMcu();
    Serial.begin(115200);
    nodeId = SYNC_ID;
    txNumber = 1;
    Rssi = 0;
    newCmd = false;

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

    pinMode(BTN_PIN, INPUT_PULLUP);

    turnOnRGB(COLOR_SEND, 0);
    packet syncPacket(0, TTL, nodeId);
    sendPacket(syncPacket);
    lastSync = millis();
    state = LOWPOWER;
}

void loop()
{
    switch (state)
    {
    case RX:
        turnOnRGB(0, 0);
        Radio.Rx(0);

        newCmd = digitalRead(BTN_PIN) == LOW;

        if (nodeId == SYNC_ID && millis() - lastSync > INIT_TIMEOUT)
        {
            Serial.printf("\n\rGot %u SYNC responses, setting my nodeID: %u\n\n", stack.getSize(), stack.getMaxSyncId());
            nodeId = stack.getMaxSyncId() + 1;
            stack.clear();
            state = RX;
            lastSync = millis();
            txNumber += 1;
            break;
        }

        if (newCmd) // SENDING A NEW COMMAND
        {
            txNumber += 1;
            packet packet(txNumber, TTL, COMMAND, 0, 0);
            sendPacket(packet);
            state = LOWPOWER;
            break;
        }

        state = RX;
        break;

    case LOWPOWER:
        turnOnRGB(0, 0);
        lowPowerHandler();
        break;

    default:
        break;
    }

    Radio.IrqProcess();
}

void OnTxDone(void)
{
    Serial.print("\n\rTX done......");
    if (nodeId != SYNC_ID)
    {
        Serial.print("\n\rPushing packet to stack.");
        stack.push(txPacket.getStruct());
        newCmd = false;
    }
    turnOnRGB(0, 0);
    state = RX;
    Serial.print("\n\rGoing to RX!");
    Serial.printf(" - nodeId: %u", nodeId);
}

void OnTxTimeout(void)
{
    Radio.Sleep();
    Serial.print("\n\rTX Timeout, retrying. ");
    sendPacket(txPacket);
    state = LOWPOWER;
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
    Rssi = rssi;
    rxSize = size;
    Snr = snr;
    packet packet(payload);
    turnOnRGB(COLOR_RECEIVED, 0);
    Radio.Sleep();

    Serial.printf("\r\nReceived packet ");
    packet.debug();
    Serial.printf("Rssi %d, SNR %d and length %d\n\n", Rssi, Snr, rxSize);

    if (packet.getTtl() <= 0)
    {
        Serial.print("\r\nTTL timeout, ignoring.");
        state = RX;
        return;
    }

    if (packet.getType() == SYNC)
    {
        Serial.printf("\r\nGot SYNC packet, my nodeId is %u and it's been %ums since last sync (tresh %ums)", nodeId, millis() - lastSync, INIT_TIMEOUT);
        if (nodeId == SYNC_ID && millis() - lastSync <= INIT_TIMEOUT)
        {
            Serial.print("\n\rReceived an existing ID packet.");
            stack.push(packet.getStruct());
            state = RX;
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
        state = LOWPOWER;
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
        txNumber = packet.getId() > txNumber ? packet.getId() : txNumber;
        sendPacket(packet);
        state = LOWPOWER;
        //Execute command here?
        return;
    }

    Serial.print("\r\nUnknown packet type, ignoring.");
    state = RX;
    return;
}

void sendPacket(packet packet)
{
    Serial.print("\n\n\n\rCLONING:\n\r");
    packet.debug();
    txPacket.clone(packet);
    txPacket.debug();
    delay(TX_DLY * nodeId);
    packet.decreaseTtl();
    turnOnRGB(COLOR_SEND, 0);

    Serial.print("\r\nSending packet:");
    packet.debug();

    byte payload[BUFFER_SIZE];
    Serial.printf("\r\n%X with length %d.\n\n", payload, sizeof(payload));
    packet.getPayload(payload);
    Radio.Send(payload, sizeof(payload));
}