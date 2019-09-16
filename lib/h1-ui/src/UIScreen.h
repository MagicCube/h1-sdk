#pragma once

#include <Arduino.h>

#include <h1.CoreGraphics.h>

// A class represents the screen.
class UIScreenClass {
public:
  // Creates a new instance of `UIScreenClass`.
  UIScreenClass();

  // Initializes the screen.
  void begin();

  // Gets a `CGDisplay` which represents the display of the screen.
  CGDisplay *display();

  // Sets the rotation of the screen.
  void rotation(uint8_t rotation);

  // Gets the bounds of the screen.
  CGRect frame();

  // Gets the bounds of the screen.
  CGRect bounds();

  // Gets the origin of the screen.
  CGPoint origin();

  // Gets the size of the screen.
  CGSize size();

  // Creates a new `CGDrawingContext` for the screen.
  CGDrawingContext *createDrawingContext(CGRect specificFrame = CGRectZero);

private:
  CGDisplay *_display;
};

// The singleton of `UIScreenClass` which represents the main screen of display device.
extern UIScreenClass UIScreen;