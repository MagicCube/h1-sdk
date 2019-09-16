#pragma once

#include <Arduino.h>

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
