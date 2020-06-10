#include <btnPanel.h>

btnPanel::btnPanel(uint8_t btn1Pin, uint8_t btn2Pin, uint8_t btn3Pin, uint8_t btn4Pin,
                   uint8_t led1Pin, uint8_t led2Pin, uint8_t led3Pin, uint8_t led4Pin)
    : btnPins{btn1Pin, btn2Pin, btn3Pin, btn4Pin},
      ledPins{led1Pin, led2Pin, led3Pin, led4Pin},
      blinkTime{0, 0, 0, 0}
{
}

void btnPanel::begin()
{
    for (uint8_t i : btnPins)
    {
        pinMode(i, INPUT);
    }

    for (uint8_t i : ledPins)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }

    state = 0x00;
    leds = 0x00;
}

void btnPanel::readButtons()
{
    state = 0x00;
    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {
        state |= !digitalRead(btnPins[i]) << i;
    }
}

void btnPanel::refreshLeds()
{
    blinkLed();
    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {
        //Serial.printf("\n\ri:%u, leds: %u, thisLed: %u", i, leds, (leds & (0x01 << i)) > 0 ? HIGH : LOW);
        digitalWrite(ledPins[i], (leds & (0x01 << i)) > 0 ? HIGH : LOW);
    }
}

void btnPanel::blinkLed(uint8_t led, uint32_t time)
{
    blinkTime[led] = time;
    blinkLed();
}

void btnPanel::blinkLed(uint8_t led)
{
    blinkTime[led] = DEFAULT_BLINK_TIME;
    blinkLed();
}

void btnPanel::blinkLed()
{
    for (uint8_t i = 0; i < N_BUTTONS; i++)
    {
        if (blinkTime[i] == 0)
        {
            continue;
        }
        if (blinkTime[i] <= millis() - timestamp[i])
        {
            timestamp[i] = millis();
            ledToggle(i);
            continue;
        }
    }
}

void btnPanel::ledOn(uint8_t led)
{
    blinkTime[led] = 0;
    setLed(led);
}

void btnPanel::setLed(uint8_t led)
{
    leds |= 0x01 << led;
}

void btnPanel::ledOff(uint8_t led)
{
    blinkTime[led] = 0;
    clearLed(led);
}

void btnPanel::clearLed(uint8_t led)
{
    leds &= 0x00 << led;
}

void btnPanel::ledToggle(uint8_t led)
{
    leds ^= 0x01 << led;
}

bool btnPanel::getButton(uint8_t btn)
{
    return (state & (0x01 << btn)) > 0;
}

uint8_t btnPanel::getLedState(uint8_t led)
{
    if (blinkTime[led] > 0)
    {
        return BLINKING;
    }
    return (leds & (0x01 << led)) / (0x01 << led);
}