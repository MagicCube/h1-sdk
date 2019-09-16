#pragma once

#include <Arduino.h>

#include "CGCanvas.h"
#include "colors.h"
#include "types.h"

// A class describes visual content using draw, push, and pop commands.
// A drawing context can be created from screen, views or a bitmap.
//
// NOTE: All the drawing and filling commands are in relative coordinate.
class CGDrawingContext : public CGCanvas {
public:
  // Creates a new instance of `CGDrawingContext`.
  CGDrawingContext(CGDrawable *drawable, CGRect frame);

  CGDrawingContext(CGCanvas *canvas) : CGDrawingContext(canvas, canvas->frame()) {
  }

  CGRect frame() override {
    return _frame;
  }

  CGRect bounds() override {
    return _bounds;
  }

  CGPoint origin() override {
    return _frame.origin;
  }

  CGSize size() override {
    return _frame.size;
  }

  CGFontFamily fontFamily() override;

  void fontFamily(CGFontFamily value) override;

  uint8_t fontSize() override;

  void fontSize(uint8_t value) override;

  CGColor textColor() override;

  void textColor(CGColor value) override;

  void drawPixel(CGPoint point, CGColor color) override;

  void drawLine(CGPoint p1, CGPoint p2, CGColor color) override;

  void drawFastVLine(CGPoint origin, CGInt height, CGColor color) override;

  void drawFastHLine(CGPoint origin, CGInt width, CGColor color) override;

  void drawRect(CGRect rect, CGColor color) override;

  void drawRoundRect(CGRect rect, CGInt roundness, CGColor color) override;

  void drawCircle(CGPoint center, CGInt radius, CGColor color) override;

  void drawString(String string, CGPoint position) override;

  void fill(CGColor color) override;

  void fillRect(CGRect rect, CGColor color) override;

  void fillRoundRect(CGRect rect, CGInt roundness, CGColor color) override;

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
