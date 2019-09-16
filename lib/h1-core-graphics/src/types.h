#pragma once

#include <Arduino.h>

// Define the pixel type of 2D system.
// Normally it's `int16_t`.
typedef int16_t CGInt;

// Define the color type.
// Normally it's 16 bit.
typedef uint16_t CGColor;

// Specify the depth of color, also known as BPP (Bit per Pixel).
enum class CGColorDepth {
  // 1-bit color which contains 2 colors.
  MONO_1_BIT = 1,

  // 8-bit color which contains 256 colors.
  COLOR_8_BIT = 8,

  // 16-bit color which contains 65,536 colors.
  COLOR_16_BIT = 16
};

// Specify the text alignment.
enum class CGTextAlign { LEFT, CENTER, RIGHT };

// Specify the baseline of text.
enum class CGTextBaseline { TOP, MIDDLE, BOTTOM };
