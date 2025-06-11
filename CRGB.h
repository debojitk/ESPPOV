#ifndef CRGB_H
#define CRGB_H

#include <stdint.h>

struct CRGB {
	union {
		struct {
			union { uint8_t r; uint8_t red; };
			union { uint8_t g; uint8_t green; };
			union { uint8_t b; uint8_t blue; };
		};
		uint8_t raw[3];
	};

	// Constructors
	CRGB() : r(0), g(0), b(0) {}
	CRGB(uint8_t red, uint8_t green, uint8_t blue) : r(red), g(green), b(blue) {}

	// Predefined color constants
	static const CRGB Red;
	static const CRGB Green;
	static const CRGB Blue;
	static const CRGB White;
	static const CRGB Black;
	static const CRGB Yellow;
	static const CRGB Cyan;
	static const CRGB Magenta;
	static const CRGB Orange;
	static const CRGB Purple ;
};

#endif
