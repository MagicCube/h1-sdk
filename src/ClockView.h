#pragma once

#include <Arduino.h>

#include <h1.UI.h>

class ClockView : public UIView {
public:
  ClockView(CGRect frame) : UIView(frame) {
  }

  void update() {
    if (millis() - _lastRedrawTime > 1000) {
      setNeedsRedraw();
    }
  }

  void draw() override {
    auto now = millis();
    auto context = UIScreen.createDrawingContext(frame());
    context->fill(CGCOLOR_RED);
    context->setupFont(CGFontFamily::DIGITAL_7_SEGMENT_48PX);
    context->setupTextStyle(CGTextAlign::CENTER, CGTextBaseline::MIDDLE, CGCOLOR_WHITE);
    context->drawString(formatDuration(now), bounds().center());
    _lastRedrawTime = now;
  }

private:
  unsigned long _lastRedrawTime = 0;
};
