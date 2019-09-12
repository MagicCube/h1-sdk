#pragma once

#include <Arduino.h>

#include <TFT_eSPI.h>

#include "CGPoint.h"
#include "CGRect.h"
#include "CGSize.h"
#include "types.h"

// A class describes visual content using draw, push, and pop commands.
// A drawing context can be created from screen, views or a bitmap.
//
// NOTE: All the drawing and filling commands are in relative coordinate.
class CGDrawingContext {
public:
  // Creates a new instance of `CGDrawingContext`.
  // The `drawable` could be a `TFT_eSPI` or `TFT_eSprite`.
  CGDrawingContext(TFT_eSPI *drawable, CGRect frame, bool inMemory);

  // Gets a `CGRect` represents origin and size of the contextual canvas in
  // absolute coordinate.
  CGRect frame();

  // Draws a pixel at given point.
  void drawPixel(CGPoint point, cg_color_t color);

  // Draws a line connecting 2 given points.
  void drawLine(CGPoint p1, CGPoint p2, cg_color_t color);

  // Draws a vertical line from origin with given length.
  void drawFastVLine(CGPoint origin, cg_unit_t height, cg_color_t color);

  // Draws a horizontal line from origin with given length.
  void drawFastHLine(CGPoint origin, cg_unit_t width, cg_color_t color);

  // Draws the specific rectangle.
  void drawRect(CGRect rect, cg_color_t color);

  // Draws the specific round rectangle.
  void drawRoundRect(CGRect rect, cg_unit_t roundness, cg_color_t color);

  // Draws the specific circle.
  void drawCircle(CGPoint center, cg_unit_t radius, cg_color_t color);

  // Draws text at given position.
  // You can specify font and color by `font(v)`, `fontSize(v)` and
  // `textColor(v)`, while use `textAlign(v)` to set text alignment.
  void drawString(String string, CGPoint position);

  // Fills the contextual canvas with given color.
  void fill(cg_color_t color);

  // Fills the specific rectangle;
  void fillRect(CGRect rect, cg_color_t color);

  // Fills the specific round rectangle;
  void fillRoundRect(CGRect rect, cg_unit_t roundness, cg_color_t color);

  // Fills the specific circle;
  void fillCircle(CGPoint center, cg_unit_t radius, cg_color_t color);

  // Translates a local x-coordinate value to absolute.
  cg_unit_t translateX(cg_unit_t relativeX) {
    return _frame.origin.x + relativeX;
  }

  // Translates a local y-coordinate value to absolute.
  cg_unit_t translateY(cg_unit_t relativeY) {
    return _frame.origin.y + relativeY;
  }

  // Translates a local coordinate point to absolute.
  CGPoint translatePoint(CGPoint relativePoint) {
    if (_zeroTranslation) {
      return relativePoint;
    }
    return CGPoint(translateX(_frame.origin.x), translateY(_frame.origin.y));
  }

  // Translates a local coorinate rectangle to absolute.
  CGRect translateRect(CGRect relativeRect) {
    if (_zeroTranslation) {
      return relativeRect;
    }
    return CGRect(translatePoint(relativeRect.origin), relativeRect.size);
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

  TFT_eSPI *_drawable;
};
