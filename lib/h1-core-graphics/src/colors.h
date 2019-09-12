#pragma once

#include "types.h"

#define CG_COLOR_BLACK 0x0000       /*   0,   0,   0 */
#define CG_COLOR_NAVY 0x000F        /*   0,   0, 128 */
#define CG_COLOR_DARKGREEN 0x03E0   /*   0, 128,   0 */
#define CG_COLOR_DARKCYAN 0x03EF    /*   0, 128, 128 */
#define CG_COLOR_MAROON 0x7800      /* 128,   0,   0 */
#define CG_COLOR_PURPLE 0x780F      /* 128,   0, 128 */
#define CG_COLOR_OLIVE 0x7BE0       /* 128, 128,   0 */
#define CG_COLOR_LIGHTGREY 0xC618   /* 192, 192, 192 */
#define CG_COLOR_DARKGREY 0x7BEF    /* 128, 128, 128 */
#define CG_COLOR_BLUE 0x001F        /*   0,   0, 255 */
#define CG_COLOR_GREEN 0x07E0       /*   0, 255,   0 */
#define CG_COLOR_CYAN 0x07FF        /*   0, 255, 255 */
#define CG_COLOR_RED 0xF800         /* 255,   0,   0 */
#define CG_COLOR_MAGENTA 0xF81F     /* 255,   0, 255 */
#define CG_COLOR_YELLOW 0xFFE0      /* 255, 255,   0 */
#define CG_COLOR_WHITE 0xFFFF       /* 255, 255, 255 */
#define CG_COLOR_ORANGE 0xFDA0      /* 255, 180,   0 */
#define CG_COLOR_GREENYELLOW 0xB7E0 /* 180, 255,   0 */
#define CG_COLOR_PINK 0xFC9F

// Convert RGB color to a 16 bit `cg_color_t` value.
inline cg_color_t cg_color_rgb(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
