#pragma once

#include <Arduino.h>

#include <TFT_eSPI.h>

// A class stores the single instance of TFT_eSPI display.
class CGDisplayClass {
public:
  CGDisplayClass();

  // Gets the native `TFT_eSPI`.
  TFT_eSPI *nativeTFT();

  // Initializes the `CGDisplay`.
  void begin();

private:
  TFT_eSPI *_nativeTFT;
};

extern CGDisplayClass CGDisplay;
