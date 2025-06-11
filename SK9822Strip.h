#ifndef SK9822STRIP_H
#define SK9822STRIP_H

#include <Arduino.h>
#include <SPI.h>
#include "CRGB.h"

class SK9822Strip {
public:
    SK9822Strip(uint8_t num_leds, CRGB* led_data, uint8_t brightness = 31);
    void begin();
    void show();
    void clear();

private:
    uint8_t _num_leds;
    CRGB* _leds;
    uint8_t _startFrame[4] = {0x00, 0x00, 0x00, 0x00};
    uint8_t _endFrame[5]   = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t *_buffer __attribute__((aligned(4)));
    uint8_t _brightness = 31;
};

#endif
