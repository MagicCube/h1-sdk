#pragma once

#include <Arduino.h>

#include "CGCanvas.h"

// An abstract class represents a display.
class CGDisplay : public CGCanvas {
public:
  // Initializes the `CGDisplay`.
  virtual void begin() = 0;
};
