
#ifndef __TTY_H
#define __TTY_H

#include <stdint.h>
#include <stddef.h>

void termInit ();

enum colors {
	black = 0,
	blue = 1,
	green = 2,
	cyan = 3,
	red = 4,
	magenta = 5,
	brown = 6,
	white = 7,
	darkGrey = 8,
	lightBlue = 9,
	lightGreen = 10,
	lightCyan = 11,
	lightRed = 12,
	lightMagenta = 13,
	lightBrown = 14,
	brightWhite = 15,
};

static inline uint8_t color ( enum colors fg, enum colors bg ) {
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}

#endif