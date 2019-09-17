#pragma once

#include <Arduino.h>

#include "CGCanvas.h"
#include "CGDrawingContext.h"

// An abstract class represents a display.
class CGDisplay : public CGCanvas {
public:
  // Initializes the `CGDisplay`.
  virtual void begin(CGColorDepth colorDepth) = 0;

  virtual void update(){};

  // Set rotation of the display.
  virtual void rotation(uint8_t rotation) = 0;

  // Creates a new `CGDrawingContext` for the display.
  CGDrawingContext *createDrawingContext(CGRect specificFrame = CGRectZero) {
    if (specificFrame.equals(CGRectZero)) {
      return new CGDrawingContext(this, frame());
    }
    return new CGDrawingContext(this, specificFrame);
  }
};
