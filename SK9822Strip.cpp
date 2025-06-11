#include "SK9822Strip.h"

SK9822Strip::SK9822Strip(uint8_t num_leds, CRGB* led_data, uint8_t brightness)
    : _num_leds(num_leds), _leds(led_data), _brightness(brightness) {
	_buffer = new uint8_t[_num_leds * 4];
}

void SK9822Strip::begin() {
    SPI.begin();
    SPI.setFrequency(24000000L); // You can tweak up to 24–30MHz safely for SK9822
    SPI.setBitOrder(MSBFIRST);
}

void SK9822Strip::show() {
    SPI.writeBytes(_startFrame, 4);
    for (int i = 0; i < _num_leds; i++) {
        int offset = i * 4;
        _buffer[offset]     = 0b11100000 | (_brightness & 0x1F); // brightness;
        _buffer[offset + 1] = _leds[i].b;
        _buffer[offset + 2] = _leds[i].g;
        _buffer[offset + 3] = _leds[i].r;
    }
    SPI.writeBytes(_buffer, _num_leds * 4); // Enough to latch up to ~150 LEDs
    SPI.writeBytes(_endFrame, 5); // Enough to latch up to ~150 LEDs
}

void SK9822Strip::clear() {
    for (uint16_t i = 0; i < _num_leds; ++i) {
        _leds[i].r = 0;
        _leds[i].g = 0;
        _leds[i].b = 0;
    }
    show();
}
