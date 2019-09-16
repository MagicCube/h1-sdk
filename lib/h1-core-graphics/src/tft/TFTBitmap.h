#pragma once

#include <Arduino.h>

#include <TFT_eSPI.h>

#include "../CGBitmap.h"

// A class represents TFT bitmap.
class TFTBitmap : CGBitmap {
public:
  // Creates a new instance of `TFTBitmap`.
  TFTBitmap(CGSize size, CGColorDepth colorDepth);

  ~TFTBitmap() override;

  CGRect bounds() override {
    return _bounds;
  }

  CGRect frame() override {
    return _bounds;
  }

  CGPoint origin() override {
    return _bounds.origin;
  }

  CGSize size() override {
    return _bounds.size;
  }

  CGFontFamily fontFamily() override;

  void fontFamily(CGFontFamily value) override;

  uint8_t fontSize() override;

  void fontSize(uint8_t value) override;

  CGColor textColor() override;

  void textColor(CGColor value) override;

  void alloc() override;

  void free() override;

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

private:
  CGRect _bounds;
  CGColorDepth _colorDepth;

  CGColor _textColor = CGCOLOR_WHITE;
  CGFontFamily _fontFamily = CGFontFamily::ADAFRUIT_8PX;
  uint8_t _fontSize = 1;

  TFT_eSprite *_nativeSprite;
};
