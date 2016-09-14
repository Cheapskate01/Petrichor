
#include <stddef.h>
#include <stdint.h>

#include "tty.h"

static const size_t scrW = 80;
static const size_t scrH = 25;
static size_t curX;
static size_t curY;
static uint16_t* const vgaMem = (uint16_t*) 0xB8000;
static uint8_t termColor;
static uint16_t* video;

void termInit () {
	curX = 0;
	curY = 0;
	termColor = color ( white, darkGrey );
	video = vgaMem;
	for (size_t y = 0; y < scrH; y++) {
		for (size_t x = 0; x < scrW; x++) {
			const size_t index = y * scrW + x;
			video[index] = vga_entry(' ', termColor);
		}
	}

}