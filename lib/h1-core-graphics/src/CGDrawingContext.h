#pragma once

#include <Arduino.h>

#include <TFT_eSPI.h>

#include "CGPoint.h"
#include "CGRect.h"
#include "CGSize.h"
#include "colors.h"
#include "types.h"

// A class describes visual content using draw, push, and pop commands.
// A drawing context can be created from screen, views or a bitmap.
//
// NOTE: All the drawing and filling commands are in relative coordinate.
class CGDrawingContext {
public:
  // Creates a new instance of `CGDrawingContext`.
  // The `nativeTFT` could be a `TFT_eSPI` or `TFT_eSprite`.
  CGDrawingContext(TFT_eSPI *nativeTFT, CGRect frame, bool inMemory);

  // Creates a new instance of `CGDrawingContext`.
  // The `nativeTFT` could be a `TFT_eSPI` or `TFT_eSprite`.
  CGDrawingContext(TFT_eSPI *nativeTFT, CGSize size, bool inMemory);

  // Gets a `CGRect` represents origin and size of the contextual canvas in
  // absolute coordinate.
  CGRect frame();

  // Shortcuts for `frame().origin`.
  CGPoint origin() {
    return frame().origin;
  }

  // Shortcuts for `frame().size`.
  CGSize size() {
    return frame().size;
  }

  // Gets current font family.
  CGFontFamily fontFamily();

  // Sets current font family.
  void fontFamily(CGFontFamily value);

  // Gets current font size.
  uint8_t fontSize();

  // Sets current font size.
  void fontSize(uint8_t value);

  // Gets current text color.
  CGColor textColor();

  // Sets current text color.
  void textColor(CGColor value);

  // Draws a pixel at given point.
  void drawPixel(CGPoint point, CGColor color);

  // Draws a line connecting 2 given points.
  void drawLine(CGPoint p1, CGPoint p2, CGColor color);

  // Draws a vertical line from origin with given length.
  void drawFastVLine(CGPoint origin, CGInt height, CGColor color);

  // Draws a horizontal line from origin with given length.
  void drawFastHLine(CGPoint origin, CGInt width, CGColor color);

  // Draws the specific rectangle.
  void drawRect(CGRect rect, CGColor color);

  // Draws the specific round rectangle.
  void drawRoundRect(CGRect rect, CGInt roundness, CGColor color);

  // Draws the specific circle.
  void drawCircle(CGPoint center, CGInt radius, CGColor color);

  // Draws text at given position.
  // You can specify font and color by `font(v)`, `fontSize(v)` and
  // `textColor(v)`, while use `textAlign(v)` to set text alignment.
  void drawString(String string, CGPoint position);

  // Fills the contextual canvas with given color.
  void fill(CGColor color);

  // Fills the specific rectangle;
  void fillRect(CGRect rect, CGColor color);

  // Fills the specific round rectangle;
  void fillRoundRect(CGRect rect, CGInt roundness, CGColor color);

  // Fills the specific circle;
  void fillCircle(CGPoint center, CGInt radius, CGColor color);

  // Converts a local x-coordinate value to absolute.
  CGInt convertToAbsoluteY(CGInt relativeX) {
    return _frame.origin.x + relativeX;
  }

  // Converts a local y-coordinate value to absolute.
  CGInt convertToAbsoluteX(CGInt relativeY) {
    return _frame.origin.y + relativeY;
  }

  // Returns a new `CGPoint` which converted a local coordinate point to absolute.
  CGPoint convertToAbsolute(CGPoint relativePoint) {
    if (_zeroTranslation) {
      return relativePoint;
    }
    return CGPoint(convertToAbsoluteX(relativePoint.x), convertToAbsoluteY(relativePoint.y));
  }

  // Returns a new `CGRect` which converted a local coorinate rectangle to absolute.
  CGRect convertToAbsolute(CGRect relativeRect) {
    if (_zeroTranslation) {
      return relativeRect;
    }
    return CGRect(convertToAbsolute(relativeRect.origin), relativeRect.size);
  }

protected:
  // Creates a new instance of `CGDrawingContext`.
  CGDrawingContext(CGRect frame, bool inMemory);

private:
  CGRect _frame;

  // True if the origin of this context is (0, 0).
  bool _zeroTranslation;

  // True if the context is a sprite.
  bool _inMemory;

  CGColor _textColor = CGCOLOR_WHITE;
  CGFontFamily _fontFamily = CGFontFamily::ADAFRUIT_8PX;
  uint8_t _fontSize = 1;

  TFT_eSPI *_nativeTFT;
};
