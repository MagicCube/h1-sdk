#pragma once

#include <Arduino.h>

#include "CGDrawingContext.h"
#include "CGSize.h"
#include "types.h"

// A class represents bitmap.
class CGBitmap {
public:
  // Creates a new instance of `CGBitmap`.
  // It will also allocate memory automatically, so you don't have to manually
  // invoke `alloc()`.
  CGBitmap(CGSize size, CGColorDepth colorDepth);

  ~CGBitmap();

  // Gets the bounds of the bitmap.
  CGRect bounds();

  // Gets the size of the bitmap.
  CGSize size();

  // Gets the color depth of the bitmap.
  CGColorDepth colorDepth();

  // Allocates memory for the bitmap.
  void alloc();

  // Frees the allocated memory of the bitmap.
  void free();

  // Creates a new `CGDrawingContext` for the bitmap.
  // The returned `CGDrawingContext` has already been allocated.
  CGDrawingContext *createDrawingContext();

private:
  CGRect _bounds;
  CGColorDepth _colorDepth;
  TFT_eSprite *_sprite;
};
