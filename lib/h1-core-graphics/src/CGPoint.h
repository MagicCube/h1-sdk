#pragma once

#include <Arduino.h>

#include "types.h"

// A struct represents a 2D point.
struct CGPoint {
  // The x-coordinate of the point.
  CGInt x = 0;

  // The y-coordinate of the point.
  CGInt y = 0;

  // Creates a new `CGPoint` with given `x` and `y`.
  CGPoint(CGInt p_x = 0, CGInt p_y = 0) {
    x = p_x;
    y = p_y;
  }

  // Returns true if the given point is as same as this point.
  bool equals(CGPoint value) {
    return value.x == x && value.y == y;
  }

  // Returns a new `CGPoint` which displace given distance from thie current point.
  CGPoint translateBy(CGInt offsetX, CGInt offsetY) {
    return CGPoint(x + offsetX, y + offsetY);
  }
};

// The point whose location is (0, 0).
static const CGPoint CGPointZero(0, 0);
