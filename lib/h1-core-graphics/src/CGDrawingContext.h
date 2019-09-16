#pragma once

#include <Arduino.h>

#include "CGCanvas.h"
#include "CGColor.h"
#include "types.h"

// A class describes visual content using draw, push, and pop commands.
// A drawing context can be created from screen, views or a bitmap.
//
// NOTE: All the drawing and filling commands are in relative coordinate.
class CGDrawingContext : public CGCanvas {
public:
  // Creates a new instance of `CGDrawingContext`.
  CGDrawingContext(CGDrawable *drawable, CGRect frame);

  // Creates a new instance of `CGDrawingContext` with the same frame of the given `canvas`.
  CGDrawingContext(CGCanvas *canvas) : CGDrawingContext(canvas, canvas->frame()) {
  }

  // Gets a `CGRect` represents origin and size of the contextual drawable in
  // parental coordinate.
  CGRect frame() override {
    return _frame;
  }

  // Gets a `CGRect` represents origin and size of the contextual drawable in
  // relative coordinate which location is always (0, 0).
  CGRect bounds() override {
    return _bounds;
  }

  // Gets the origin of the contextual drawable in parental coordinate.
  CGPoint origin() override {
    return _frame.origin;
  }

  // Gets the size of the drawable object.
  CGSize size() override {
    return _frame.size;
  }

  // Gets current font family.
  CGFontFamily fontFamily() override;

  // Sets current font family.
  void fontFamily(CGFontFamily value) override;

  // Gets current font size.
  uint8_t fontSize() override;

  // Sets current font size.
  void fontSize(uint8_t value) override;

  // Gets current text color.
  CGColor textColor() override;

  // Sets current text color.
  void textColor(CGColor value) override;

  // Gets current text alignment.
  CGTextAlign textAlign() override;

  // Sets current text alignment.
  void textAlign(CGTextAlign value) override;

  // Gets current text baseline.
  CGTextBaseline textBaseline() override;

  // Sets current text baseline.
  void textBaseline(CGTextBaseline value) override;

  // Draws a pixel at given point.
  void drawPixel(CGPoint point, CGColor color) override;

  // Draws a line connecting 2 given points.
  void drawLine(CGPoint p1, CGPoint p2, CGColor color) override;

  // Draws a vertical line from origin with given length.
  void drawFastVLine(CGPoint origin, CGInt height, CGColor color) override;

  // Draws a horizontal line from origin with given length.
  void drawFastHLine(CGPoint origin, CGInt width, CGColor color) override;

  // Draws the specific rectangle.
  void drawRect(CGRect rect, CGColor color) override;

  // Draws the specific round rectangle.
  void drawRoundRect(CGRect rect, CGInt roundness, CGColor color) override;

  // Draws the specific circle.
  void drawCircle(CGPoint center, CGInt radius, CGColor color) override;

  // Draws text at given position.
  // You can specify font and color by `font(v)`, `fontSize(v)` and
  // `textColor(v)`, while use `textAlign(v)` and `textBaseline(v)` to set text
  // alignment.
  void drawString(String string, CGPoint position) override;

  // Draws the specific bitmap at given position.
  void drawBitmap(CGBitmap *bitmap, CGPoint position) override;

  // Draws the transparental bitmap at given position.
  virtual void drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor);

  // Fills the contextual drawable with given color.
  void fill(CGColor color) override;

  // Fills the specific rectangle;
  void fillRect(CGRect rect, CGColor color) override;

  // Fills the specific round rectangle.
  void fillRoundRect(CGRect rect, CGInt roundness, CGColor color) override;

  // Fills the specific circle.
  void fillCircle(CGPoint center, CGInt radius, CGColor color) override;

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

private:
  CGRect _frame;
  CGRect _bounds;

  // True if the origin of this context is (0, 0).
  bool _zeroTranslation;

  CGDrawable *_drawable;
};
