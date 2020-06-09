#ifndef BTNPANEL_H
#define BTNPANEL_H

#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>

#define N_BUTTONS 4
#define DEFAULT_BLINK_TIME 500

class btnPanel
{
public:
    uint8_t state;
    uint8_t leds;

    btnPanel(uint8_t btn1Pin, uint8_t btn2Pin, uint8_t btn3Pin, uint8_t btn4Pin,
             uint8_t led1Pin, uint8_t led2Pin, uint8_t led3Pin, uint8_t led4Pin);
    void begin();
    void readButtons();
    void refreshLeds();
    void blinkLed(uint8_t led, uint32_t time);
    void blinkLed(uint8_t led);
    void ledOn(uint8_t led);
    void ledOff(uint8_t led);
    void ledToggle(uint8_t led);
    bool getButton(uint8_t btn);
    uint8_t getLedState(uint8_t led);

private:
    uint8_t btnPins[N_BUTTONS];
    uint8_t ledPins[N_BUTTONS];
    uint32_t blinkTime[N_BUTTONS];
    uint32_t timestamp[N_BUTTONS];
     
    void blinkLed();
    void setLed(uint8_t led);
    void clearLed(uint8_t led);
};

typedef enum
{
    OFF = 0,
    ON = 1,
    BLINKING = 2
} ledStates;

#endif