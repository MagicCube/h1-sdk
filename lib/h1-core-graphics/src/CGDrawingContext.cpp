#include "CGDrawingContext.h"

CGDrawingContext::CGDrawingContext(CGDrawable *drawable, CGRect frame) {
  _drawable = drawable;
  _frame = frame;
  _bounds = CGRect(CGPointZero, _frame.size);
  _zeroTranslation = _frame.origin.equals(CGPointZero);
}

CGFontFamily CGDrawingContext::fontFamily() {
  return _drawable->fontFamily();
}

void CGDrawingContext::fontFamily(CGFontFamily value) {
  _drawable->fontFamily(value);
}

uint8_t CGDrawingContext::fontSize() {
  return _drawable->fontSize();
}

void CGDrawingContext::fontSize(uint8_t value) {
  _drawable->fontSize(value);
}

CGColor CGDrawingContext::textColor() {
  return _drawable->textColor();
}

void CGDrawingContext::textColor(CGColor value) {
  _drawable->textColor(value);
}

CGTextAlign CGDrawingContext::textAlign() {
  return _drawable->textAlign();
}

void CGDrawingContext::textAlign(CGTextAlign value) {
  _drawable->textAlign(value);
}

CGTextBaseline CGDrawingContext::textBaseline() {
  return _drawable->textBaseline();
}

void CGDrawingContext::textBaseline(CGTextBaseline value) {
  _drawable->textBaseline(value);
}

void CGDrawingContext::drawPixel(CGPoint point, CGColor color) {
  auto absPoint = convertToAbsolute(point);
  _drawable->drawPixel(absPoint, color);
}

void CGDrawingContext::drawLine(CGPoint p1, CGPoint p2, CGColor color) {
  auto absP1 = convertToAbsolute(p1);
  auto absP2 = convertToAbsolute(p2);
  _drawable->drawLine(absP1, absP2, color);
}

void CGDrawingContext::drawFastVLine(CGPoint origin, CGInt height, CGColor color) {
  auto absOrigin = convertToAbsolute(origin);
  _drawable->drawFastVLine(absOrigin, height, color);
}

void CGDrawingContext::drawFastHLine(CGPoint origin, CGInt width, CGColor color) {
  auto absOrigin = convertToAbsolute(origin);
  _drawable->drawFastHLine(absOrigin, width, color);
}

void CGDrawingContext::drawRect(CGRect rect, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->drawRect(absRect, color);
}

void CGDrawingContext::drawRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->drawRoundRect(absRect, roundness, color);
}

void CGDrawingContext::drawCircle(CGPoint center, CGInt radius, CGColor color) {
  auto absCenter = convertToAbsolute(center);
  _drawable->drawCircle(absCenter, radius, color);
}

void CGDrawingContext::drawString(String string, CGPoint position) {
  auto absPosition = convertToAbsolute(position);
  _drawable->drawString(string, absPosition);
}

void CGDrawingContext::drawBitmap(CGBitmap *bitmap, CGPoint position) {
  auto absPosition = convertToAbsolute(position);
  _drawable->drawBitmap(bitmap, absPosition);
}

void CGDrawingContext::drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor) {
  auto absPosition = convertToAbsolute(position);
  _drawable->drawBitmap(bitmap, absPosition, transparentColor);
}

void CGDrawingContext::fill(CGColor color) {
  _drawable->fill(color);
}

void CGDrawingContext::fillRect(CGRect rect, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->fillRect(absRect, color);
}

void CGDrawingContext::fillRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->fillRoundRect(absRect, roundness, color);
}

void CGDrawingContext::fillCircle(CGPoint center, CGInt radius, CGColor color) {
  auto absCenter = convertToAbsolute(center);
  _drawable->fillCircle(absCenter, radius, color);
}
