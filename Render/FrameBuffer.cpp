#include "Constants.h"
#include <cstdint>

uint32_t framebuffer[WIDTH * HEIGHT];

void setToWhite() {
	for (uint32_t& x: framebuffer) {
		x = white;
	}
}