#pragma once

#include <Arduino.h>

#include "types.h"

// A struct contains width and height values.
struct CGSize {
  // The width value of the size.
  CGInt width = 0;

  // The height value of the size.
  CGInt height = 0;


  // Creates a new `CGSize` with given `width` and `height`.
  CGSize(CGInt p_width = 0, CGInt p_height = 0) {
    width = p_width;
    height = p_height;
  }

  // Returns true if the given size is as same as this size.
  bool equals(CGSize value) {
    return value.width == width && value.height == height;
  }

  // Returns a new `CGSize`.
  CGSize scaleBy(CGInt xOffset, CGInt yOffset) {
    return CGSize(width + xOffset, height + yOffset);
  }
};

// The size whose width and height are both 0.
static const CGSize CGSizeZero(0, 0);
