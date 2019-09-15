#pragma once

#include <Arduino.h>

#include <TFT_eSPI.h>

#include "CGRect.h"

// A class stores the single instance of TFT_eSPI display.
class CGDisplayClass {
public:
  CGDisplayClass();

  // Gets the bounds of the display.
  CGRect bounds();

  // Gets the size of the display.
  CGSize size();

  // Gets the native `TFT_eSPI`.
  TFT_eSPI *nativeTFT();

  // Initializes the `CGDisplay`.
  void begin();

private:
  CGRect _bounds = CGRect(CGPointZero, TFT_WIDTH, TFT_HEIGHT);
  TFT_eSPI *_nativeTFT;
};

extern CGDisplayClass CGDisplay;
