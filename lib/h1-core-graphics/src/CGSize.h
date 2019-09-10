#pragma once

#include <Arduino.h>

#include "types.h"

// A struct contains width and height values.
struct CGSize {
  // Creates a new `CGSize` with given `width` and `height`.
  CGSize(cg_unit_t p_width = 0, cg_unit_t p_height = 0) {
    width = p_width;
    height = p_height;
  }

  // The width value of the size.
  cg_unit_t width = 0;

  // The height value of the size.
  cg_unit_t height = 0;
};

// The size whose width and height are both 0.
static const CGSize CGSizeZero(0, 0);
