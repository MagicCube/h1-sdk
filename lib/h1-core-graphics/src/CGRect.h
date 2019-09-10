#pragma once

#include <Arduino.h>

#include "types.h"

#include "CGPoint.h"
#include "CGSize.h"

// A struct represents a rectangle.
struct CGRect {
  // Creates a new `CGRect` with given `x`, `y`, `width` and `height`.
  CGRect(cg_unit_t p_x = 0, cg_unit_t p_y = 0, cg_unit_t p_width = 0, cg_unit_t p_height = 0) {
    origin = CGPoint(p_x, p_y);
    size = CGSize(p_width, p_height);
  }

  // Creates a new `CGRect` with given `x`, `y` and `size`.
  CGRect(cg_unit_t p_x, cg_unit_t p_y, CGSize p_size = CGSizeZero) {
    origin = CGPoint(p_x, p_y);
    size = p_size;
  }

  // Creates a new `CGRect` with given `origin`, `width` and `height`.
  CGRect(CGPoint p_origin, cg_unit_t p_width = 0, cg_unit_t p_height = 0) {
    origin = p_origin;
    size = CGSize(p_width, p_height);
  }

  // Creates a new `CGRect` with given `origin` and `size`.
  CGRect(CGPoint p_origin, CGSize p_size = CGSizeZero) {
    origin = p_origin;
    size = p_size;
  }

  // The origin of the rectangle.
  CGPoint origin;

  // The size of the rectangle.
  CGSize size;
};

// The rectangle whose width and height are both 0.
static const CGRect CGRectZero(CGPointZero, CGSizeZero);
