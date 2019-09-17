#pragma once

#include <Arduino.h>

#include "CGDisplay.h"
#include "TFTBitmap.h"
#include "TFTDisplay.h"

// A class represents a buffered TFT display.
class TFTBufferedDisplay : public CGDisplay {
public:
  void begin() override;

  void update() override;

  CGRect bounds() override {
    return _tftDisplay.bounds();
  }

  CGRect frame() override {
    return _tftDisplay.frame();
  }

  CGPoint origin() override {
    return _tftDisplay.origin();
  }

  CGSize size() override {
    return _tftDisplay.size();
  }

  bool needsRedraw() {
    return _needsRedraw;
  }

  void setNeedsRedraw() {
    _needsRedraw = true;
  }

  void rotation(uint8_t rotation) override;

  CGFontFamily fontFamily() override;

  void fontFamily(CGFontFamily value) override;

  uint8_t fontSize() override;

  void fontSize(uint8_t value) override;

  CGColor textColor() override;

  void textColor(CGColor value) override;

  CGTextAlign textAlign() override;

  void textAlign(CGTextAlign value) override;

  CGTextBaseline textBaseline() override;

  void textBaseline(CGTextBaseline value) override;

  void drawPixel(CGPoint point, CGColor color) override;

  void drawLine(CGPoint p1, CGPoint p2, CGColor color) override;

  void drawFastVLine(CGPoint origin, CGInt height, CGColor color) override;

  void drawFastHLine(CGPoint origin, CGInt width, CGColor color) override;

  void drawRect(CGRect rect, CGColor color) override;

  void drawRoundRect(CGRect rect, CGInt roundness, CGColor color) override;

  void drawCircle(CGPoint center, CGInt radius, CGColor color) override;

  void drawString(String string, CGPoint position) override;

  void drawBitmap(CGBitmap *bitmap, CGPoint position) override;

  void drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor) override;

  void drawXBM(CGXBM *xbm, CGPoint position, CGColor color) override;

  void fill(CGColor color) override;

  void fillRect(CGRect rect, CGColor color) override;

  void fillRoundRect(CGRect rect, CGInt roundness, CGColor color) override;

  void fillCircle(CGPoint center, CGInt radius, CGColor color) override;

private:
  TFTDisplay _tftDisplay;
  TFTBitmap *_buffer;
  bool _needsRedraw = true;
};
