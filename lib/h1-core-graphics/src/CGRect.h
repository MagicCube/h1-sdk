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
  CGRect(CGInt p_x = 0, CGInt p_y = 0, CGInt p_width = 0, CGInt p_height = 0) {
    origin = CGPoint(p_x, p_y);
    size = CGSize(p_width, p_height);
  }

  // Creates a new `CGRect` with given `x`, `y` and `size`.
  CGRect(CGInt p_x, CGInt p_y, CGSize p_size = CGSizeZero) {
    origin = CGPoint(p_x, p_y);
    size = p_size;
  }

  // Creates a new `CGRect` with given `origin`, `width` and `height`.
  CGRect(CGPoint p_origin, CGInt p_width = 0, CGInt p_height = 0) {
    origin = p_origin;
    size = CGSize(p_width, p_height);
  }

  // Creates a new `CGRect` with given `origin` and `size`.
  CGRect(CGPoint p_origin, CGSize p_size = CGSizeZero) {
    origin = p_origin;
    size = p_size;
  }

  // Returns a new `CGPoint` which represents the center of the rectangle.
  CGPoint center() {
    return CGPoint(origin.x + size.width / 2, origin.y + size.height / 2);
  }

  // Returns true if the given rectangle is as same as this rectangle.
  bool equals(CGRect value) {
    return value.origin.equals(origin) && value.size.equals(size);
  }

  CGRect translateBy(CGInt offsetX, CGInt offsetY) {
    return CGRect(origin.translateBy(offsetX, offsetY), size);
  }

  CGRect scaleBy(CGInt offsetX, CGInt offsetY) {
    return CGRect(origin, size.scaleBy(offsetX, offsetY));
  }

  CGRect margin(CGInt up, CGInt right, CGInt down, CGInt left) {
    return CGRect(origin.translateBy(-left, -up), size.scaleBy(left + right, up + down));
  }

  CGRect margin(CGInt marginX, CGInt marginY) {
    return margin(marginY, marginX, marginY, marginX);
  }

  CGRect margin(CGInt marginXY) {
    return margin(marginXY, marginXY);
  }

  CGRect pad(CGInt up, CGInt right, CGInt down, CGInt left) {
    return CGRect(origin.translateBy(left, up), size.scaleBy(-(left + right), -(up + down)));
  }

  CGRect pad(CGInt paddingX, CGInt paddingY) {
    return pad(paddingY, paddingX, paddingY, paddingX);
  }

  CGRect pad(CGInt paddingXY) {
    return pad(paddingXY, paddingXY);
  }
};

// The rectangle whose width and height are both 0.
static const CGRect CGRectZero(CGPointZero, CGSizeZero);
