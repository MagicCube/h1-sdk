#pragma once

#include <Arduino.h>

#include "types.h"

// A struct represents a 2D point.
struct CGPoint {
  // The x-coordinate of the point.
  cg_px_t x = 0;

  // The y-coordinate of the point.
  cg_px_t y = 0;

  // Creates a new `CGPoint` with given `x` and `y`.
  CGPoint(cg_px_t p_x = 0, cg_px_t p_y = 0) {
    x = p_x;
    y = p_y;
  }

  // Returns true if the given point is as same as this point.
  bool equals(CGPoint value) {
    return value.x == x && value.y == y;
  }

  // Returns a new `CGPoint` which displace given distance from thie current point.
  CGPoint translateBy(cg_px_t offsetX, cg_px_t offsetY) {
    return CGPoint(x + offsetX, y + offsetY);
  }
};

// The point whose location is (0, 0).
static const CGPoint CGPointZero(0, 0);
