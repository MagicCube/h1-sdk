#include "TFTBufferedDisplay.h"

void TFTBufferedDisplay::begin(CGColorDepth colorDepth) {
  _tftDisplay.begin(colorDepth);
  _buffer = new TFTBitmap(size(), colorDepth);
}

void TFTBufferedDisplay::update() {
  if (_needsRedraw) {
    _tftDisplay.drawBitmap(_buffer, CGPointZero);
    _needsRedraw = false;
  }
}

void TFTBufferedDisplay::rotation(uint8_t rotation) {
  _tftDisplay.rotation(rotation);
}

CGFontFamily TFTBufferedDisplay::fontFamily() {
  return _buffer->fontFamily();
}

void TFTBufferedDisplay::fontFamily(CGFontFamily value) {
  _buffer->fontFamily(value);
}

uint8_t TFTBufferedDisplay::fontSize() {
  return _buffer->fontSize();
}

void TFTBufferedDisplay::fontSize(uint8_t value) {
  _buffer->fontSize(value);
}

CGColor TFTBufferedDisplay::textColor() {
  return _buffer->textColor();
}

void TFTBufferedDisplay::textColor(CGColor value) {
  _buffer->textColor(value);
}

CGTextAlign TFTBufferedDisplay::textAlign() {
  return _buffer->textAlign();
}

void TFTBufferedDisplay::textAlign(CGTextAlign value) {
  _buffer->textAlign(value);
}

CGTextBaseline TFTBufferedDisplay::textBaseline() {
  return _buffer->textBaseline();
}

void TFTBufferedDisplay::textBaseline(CGTextBaseline value) {
  _buffer->textBaseline(value);
}

void TFTBufferedDisplay::drawPixel(CGPoint point, CGColor color) {
  _buffer->drawPixel(point, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawLine(CGPoint p1, CGPoint p2, CGColor color) {
  _buffer->drawLine(p1, p2, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawFastVLine(CGPoint origin, CGInt height, CGColor color) {
  _buffer->drawFastVLine(origin, height, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawFastHLine(CGPoint origin, CGInt width, CGColor color) {
  _buffer->drawFastHLine(origin, width, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawRect(CGRect rect, CGColor color) {
  _buffer->drawRect(rect, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  _buffer->drawRoundRect(rect, roundness, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawCircle(CGPoint center, CGInt radius, CGColor color) {
  _buffer->drawCircle(center, radius, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawString(String string, CGPoint position) {
  _buffer->drawString(string, position);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawBitmap(CGBitmap *bitmap, CGPoint position) {
  _buffer->drawBitmap(bitmap, position);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor) {
  _buffer->drawBitmap(bitmap, position, transparentColor);
  setNeedsRedraw();
}

void TFTBufferedDisplay::drawXBM(CGXBM *xbm, CGPoint position, CGColor color) {
  _buffer->drawXBM(xbm, position, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::fill(CGColor color) {
  _buffer->fill(color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::fillRect(CGRect rect, CGColor color) {
  _buffer->fillRect(rect, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::fillRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  _buffer->fillRoundRect(rect, roundness, color);
  setNeedsRedraw();
}

void TFTBufferedDisplay::fillCircle(CGPoint center, CGInt radius, CGColor color) {
  _buffer->fillCircle(center, radius, color);
  setNeedsRedraw();
}
