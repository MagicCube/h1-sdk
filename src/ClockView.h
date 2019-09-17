#pragma once

#include <Arduino.h>

#include <h1.UI.h>

class ClockView : public UIView {
public:
  ClockView(CGRect frame) : UIView(frame) {
    _buffer = new TFTBitmap(size(), CGColorDepth::BIT_1);
    _bufferContext = _buffer->createDrawingContext();
  }

  void update() {
    if (millis() - _lastRedrawTime > 1000) {
      setNeedsRedraw();
    }
  }

  void draw() override {
    auto now = millis();
    _bufferContext->fill(CGCOLOR_BLACK);
    _bufferContext->setupFont(CGFontFamily::DIGITAL_7_SEGMENT_48PX);
    _bufferContext->setupTextStyle(CGTextAlign::CENTER, CGTextBaseline::MIDDLE, CGCOLOR_WHITE);
    _bufferContext->drawString(formatDuration(now), bounds().center());
    UIScreen.drawingContext()->drawBitmap(_buffer, origin());
    _lastRedrawTime = now;
  }

private:
  unsigned long _lastRedrawTime = 0;
  TFTBitmap *_buffer;
  CGDrawingContext *_bufferContext;
};
