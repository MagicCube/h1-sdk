#pragma once

#include <Arduino.h>

#include <h1.CoreGraphics.h>

// A class represents the screen.
class UIScreenClass {
public:
  // Initializes the screen.
  void begin();

  // Gets the bounds of the screen.
  CGRect bounds();

  // Gets the size of the screen.
  CGSize size();

private:
};

// The singleton of `UIScreenClass` which represents the main screen of display device.
extern UIScreenClass UIScreen;
