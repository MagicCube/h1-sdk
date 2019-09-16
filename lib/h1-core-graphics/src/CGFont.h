#pragma once

#include <Arduino.h>

// Specify font family.
enum class CGFontFamily {
  /**************************************/
  /* Basic Fonts                        */
  /**************************************/

  // Original Adafruit 8 pixel font.
  ADAFRUIT_8PX = 1,

  // Small 16 pixel high font.
  SMALL_16PX = 2,

  // Medium 26 pixel high font.
  MEDIUM_26PX = 4,

  // Large 48 pixel font, only contains characters 1234567890:-.apm.
  LARGE_48PX = 6,

  // 7 segment 48 pixel font, only contains characters 1234567890:-.
  DIGITAL_7_SEGMENT_48PX = 7,

  // Large 75 pixel font, only contains characters 1234567890:-.
  LARGE_75PX = 8,


  /**************************************/
  /* Free Fonts                         */
  /**************************************/
  FREE_MONO_9PT = 11,
  FREE_MONO_12PT = 12,
  FREE_MONO_18PT = 13,
  FREE_MONO_24PT = 14,

  FREE_SANS_9PT = 15,
  FREE_SANS_12PT = 16,
  FREE_SANS_18PT = 17,
  FREE_SANS_24PT = 18,

  FREE_SERIF_9PT = 19,
  FREE_SERIF_12PT = 20,
  FREE_SERIF_18PT = 21,
  FREE_SERIF_24PT = 22
};
