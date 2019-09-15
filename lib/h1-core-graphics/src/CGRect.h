#pragma once

#include <Arduino.h>

#include "types.h"

#include "CGPoint.h"
#include "CGSize.h"

// A struct represents a rectangle.
struct CGRect {
  // The origin of the rectangle.
  CGPoint origin;

  // The size of the rectangle.
  CGSize size;

  // Creates a new `CGRect` with given `x`, `y`, `width` and `height`.
  CGRect(cg_px_t p_x = 0, cg_px_t p_y = 0, cg_px_t p_width = 0, cg_px_t p_height = 0) {
    origin = CGPoint(p_x, p_y);
    size = CGSize(p_width, p_height);
  }

  // Creates a new `CGRect` with given `x`, `y` and `size`.
  CGRect(cg_px_t p_x, cg_px_t p_y, CGSize p_size = CGSizeZero) {
    origin = CGPoint(p_x, p_y);
    size = p_size;
  }

  // Creates a new `CGRect` with given `origin`, `width` and `height`.
  CGRect(CGPoint p_origin, cg_px_t p_width = 0, cg_px_t p_height = 0) {
    origin = p_origin;
    size = CGSize(p_width, p_height);
  }

  // Creates a new `CGRect` with given `origin` and `size`.
  CGRect(CGPoint p_origin, CGSize p_size = CGSizeZero) {
    origin = p_origin;
    size = p_size;
  }

  // Returns true if the given rectangle is as same as this rectangle.
  bool equals(CGRect value) {
    return value.origin.equals(origin) && value.size.equals(size);
  }

  CGRect translateBy(cg_px_t offsetX, cg_px_t offsetY) {
    return CGRect(origin.translateBy(offsetX, offsetY), size);
  }

  CGRect scaleBy(cg_px_t offsetX, cg_px_t offsetY) {
    return CGRect(origin, size.scaleBy(offsetX, offsetY));
  }

  CGRect margin(cg_px_t up, cg_px_t right, cg_px_t down, cg_px_t left) {
    return CGRect(origin.translateBy(-left, -up), size.scaleBy(left + right, up + down));
  }

  CGRect margin(cg_px_t marginX, cg_px_t marginY) {
    return margin(marginY, marginX, marginY, marginX);
  }

  CGRect margin(cg_px_t marginXY) {
    return margin(marginXY, marginXY);
  }

  CGRect pad(cg_px_t up, cg_px_t right, cg_px_t down, cg_px_t left) {
    return CGRect(origin.translateBy(left, up), size.scaleBy(-(left + right), -(up + down)));
  }

  CGRect pad(cg_px_t paddingX, cg_px_t paddingY) {
    return pad(paddingY, paddingX, paddingY, paddingX);
  }

  CGRect pad(cg_px_t paddingXY) {
    return pad(paddingXY, paddingXY);
  }
};

// The rectangle whose width and height are both 0.
static const CGRect CGRectZero(CGPointZero, CGSizeZero);
