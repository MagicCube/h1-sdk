#pragma once

#include <Arduino.h>

// Define the pixel type of 2D system.
// Normally it's `int16_t`.
typedef int16_t CGInt;

// Define the color type.
// Normally it's 16 bit.
typedef uint16_t CGColor;

// Specify font family.
enum class CGFontFamily {
  // Original Adafruit 8 pixel font.
  ADAFRUIT_8PX = 101,

  // Small 16 pixel high font.
  SMALL_16PX = 102,

  // Medium 26 pixel high font.
  MEDIUM_26PX = 104,

  // Large 48 pixel font, only contains characters 1234567890:-.apm.
  LARGE_48PX = 106,

  // 7 segment 48 pixel font, only contains characters 1234567890:-.
  DIGITAL_7_SEGMENT_48PX = 107,

  // Large 75 pixel font, only contains characters 1234567890:-.
  LARGE_75PX = 108
};

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
enum class CGTextBaseline { TOP, CENTER, BOTTOM };
