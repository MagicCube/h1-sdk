#pragma once

#include <Arduino.h>

#include "CGColor.h"
#include "CGRect.h"

class CGBitmap;

// An abstract class represents a drawable object.
class CGDrawable {
public:
  // Gets current font family.
  virtual CGFontFamily fontFamily() = 0;

  // Sets current font family.
  virtual void fontFamily(CGFontFamily value) = 0;

  // Gets current font size.
  virtual uint8_t fontSize() = 0;

  // Sets current font size.
  virtual void fontSize(uint8_t value) = 0;

  // Gets current text color.
  virtual CGColor textColor() = 0;

  // Sets current text color.
  virtual void textColor(CGColor value) = 0;

  // Draws a pixel at given point.
  virtual void drawPixel(CGPoint point, CGColor color) = 0;

  // Draws a line connecting 2 given points.
  virtual void drawLine(CGPoint p1, CGPoint p2, CGColor color) = 0;

  // Draws a vertical line from origin with given length.
  virtual void drawFastVLine(CGPoint origin, CGInt height, CGColor color) = 0;

  // Draws a horizontal line from origin with given length.
  virtual void drawFastHLine(CGPoint origin, CGInt width, CGColor color) = 0;

  // Draws the specific rectangle.
  virtual void drawRect(CGRect rect, CGColor color) = 0;

  // Draws the specific round rectangle.
  virtual void drawRoundRect(CGRect rect, CGInt roundness, CGColor color) = 0;

  // Draws the specific circle.
  virtual void drawCircle(CGPoint center, CGInt radius, CGColor color) = 0;

  // Draws the text at given position.
  // You can specify font and color by `font(v)`, `fontSize(v)` and
  // `textColor(v)`, while use `textAlign(v)` to set text alignment.
  virtual void drawString(String string, CGPoint position) = 0;

  // Draws the specific bitmap at given position.
  virtual void drawBitmap(CGBitmap *bitmap, CGPoint position);

  // Draws the transparental bitmap at given position.
  virtual void drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor);

  // Fills the contextual canvas with given color.
  virtual void fill(CGColor color) = 0;

  // Fills the specific rectangle.
  virtual void fillRect(CGRect rect, CGColor color) = 0;

  // Fills the specific round rectangle.
  virtual void fillRoundRect(CGRect rect, CGInt roundness, CGColor color) = 0;

  // Fills the specific circle.
  virtual void fillCircle(CGPoint center, CGInt radius, CGColor color) = 0;
};
