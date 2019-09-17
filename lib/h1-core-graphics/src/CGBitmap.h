#pragma once

#include <Arduino.h>

#include "CGCanvas.h"
#include "CGDrawingContext.h"
#include "types.h"

// An abstract class represents a bitmap.
class CGBitmap : public CGCanvas {
public:
  virtual ~CGBitmap(){};

  // Gets the color depth of the bitmap
  virtual CGColorDepth colorDepth() = 0;

  // Re-allocate the memory needed by the bitmap.
  virtual void alloc() = 0;

  // Clear the memory for the bitmap.
  virtual void free() = 0;

  // Convert to 16 bit array.
  virtual uint8_t *to8BitArray();

  // Convert to 16 bit array.
  virtual uint16_t *to16BitArray();

  // Creates a new `CGDrawingContext` for the bitmap.
  CGDrawingContext *createDrawingContext(CGRect specificFrame = CGRectZero) {
    if (specificFrame.equals(CGRectZero)) {
      return new CGDrawingContext(this, frame());
    }
    return new CGDrawingContext(this, specificFrame);
  }
};
