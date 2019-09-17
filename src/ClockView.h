#pragma once

#include <Arduino.h>

#include <h1.UI.h>

class ClockView : public UIView {
public:
  ClockView(CGRect frame) : UIView(frame) {
    _buffer = new TFTBitmap(size(), CGColorDepth::BIT_1, false);
  }

  virtual ~ClockView() {
    delete _buffer;
  }

  void update() {
    if (millis() - _lastRedrawTime > 1000) {
      setNeedsRedraw();
    }
  }

  void draw() override {
    auto now = millis();
    _buffer->alloc();
    auto context = _buffer->createDrawingContext();
    context->setupFont(CGFontFamily::DIGITAL_7_SEGMENT_48PX);
    context->setupTextStyle(CGTextAlign::CENTER, CGTextBaseline::MIDDLE, CGCOLOR_WHITE);
    context->drawString(formatDuration(now), bounds().center());
    UIScreen.drawingContext()->drawBitmap(_buffer, origin());
    _buffer->free();
    _lastRedrawTime = now;
  }

private:
  unsigned long _lastRedrawTime = 0;
  TFTBitmap *_buffer;
};
