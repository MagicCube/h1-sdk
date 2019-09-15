#pragma once

#include "types.h"

#define CGCOLOR_BLACK 0x0000       /*   0,   0,   0 */
#define CGCOLOR_NAVY 0x000F        /*   0,   0, 128 */
#define CGCOLOR_DARKGREEN 0x03E0   /*   0, 128,   0 */
#define CGCOLOR_DARKCYAN 0x03EF    /*   0, 128, 128 */
#define CGCOLOR_MAROON 0x7800      /* 128,   0,   0 */
#define CGCOLOR_PURPLE 0x780F      /* 128,   0, 128 */
#define CGCOLOR_OLIVE 0x7BE0       /* 128, 128,   0 */
#define CGCOLOR_LIGHTGREY 0xC618   /* 192, 192, 192 */
#define CGCOLOR_DARKGREY 0x7BEF    /* 128, 128, 128 */
#define CGCOLOR_BLUE 0x001F        /*   0,   0, 255 */
#define CGCOLOR_GREEN 0x07E0       /*   0, 255,   0 */
#define CGCOLOR_CYAN 0x07FF        /*   0, 255, 255 */
#define CGCOLOR_RED 0xF800         /* 255,   0,   0 */
#define CGCOLOR_MAGENTA 0xF81F     /* 255,   0, 255 */
#define CGCOLOR_YELLOW 0xFFE0      /* 255, 255,   0 */
#define CGCOLOR_WHITE 0xFFFF       /* 255, 255, 255 */
#define CGCOLOR_ORANGE 0xFDA0      /* 255, 180,   0 */
#define CGCOLOR_GREENYELLOW 0xB7E0 /* 180, 255,   0 */
#define CGCOLOR_PINK 0xFC9F

// Convert RGB color to a 16 bit `CGColor` value.
inline CGColor CGColorRGB(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
