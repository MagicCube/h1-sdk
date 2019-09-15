#include "CGDrawingContext.h"

CGDrawingContext::CGDrawingContext(CGRect frame, bool inMemory) {
  _frame = frame;
  _zeroTranslation = _frame.origin.equals(CGPointZero);
  _inMemory = inMemory;
}

CGDrawingContext::CGDrawingContext(TFT_eSPI *drawable, CGRect frame, bool inMemory)
    : CGDrawingContext(frame, inMemory) {
  _drawable = drawable;
}

CGDrawingContext::CGDrawingContext(TFT_eSPI *drawable, CGSize size, bool inMemory)
    : CGDrawingContext(drawable, CGRect(CGPointZero, size), inMemory) {
}

CGRect CGDrawingContext::frame() {
  return _frame;
}

CGFontFamily CGDrawingContext::fontFamily() {
  return _fontFamily;
}

void CGDrawingContext::fontFamily(CGFontFamily value) {
  _fontFamily = value;
  uint8_t _fontFamilyValue = (uint8_t)_fontFamily;
  if (_fontFamilyValue > 100 && _fontFamilyValue < 110) {
    _drawable->setTextFont(_fontFamilyValue - 100);
  }
}

uint8_t CGDrawingContext::fontSize() {
  return _fontSize;
}

void CGDrawingContext::fontSize(uint8_t value) {
  _fontSize = value;
}

CGColor CGDrawingContext::textColor() {
  return _textColor;
}

void CGDrawingContext::textColor(CGColor value) {
  _textColor = value;
}

void CGDrawingContext::drawPixel(CGPoint point, CGColor color) {
  auto absPoint = convertToAbsolute(point);
  _drawable->drawPixel(absPoint.x, absPoint.y, color);
}

void CGDrawingContext::drawLine(CGPoint p1, CGPoint p2, CGColor color) {
  auto absP1 = convertToAbsolute(p1);
  auto absP2 = convertToAbsolute(p2);
  _drawable->drawLine(absP1.x, absP1.y, absP2.x, absP2.y, color);
}

void CGDrawingContext::drawFastVLine(CGPoint origin, CGInt height, CGColor color) {
  auto absOrigin = convertToAbsolute(origin);
  _drawable->drawFastVLine(absOrigin.x, absOrigin.y, height, color);
}

void CGDrawingContext::drawFastHLine(CGPoint origin, CGInt width, CGColor color) {
  auto absOrigin = convertToAbsolute(origin);
  _drawable->drawFastHLine(absOrigin.x, absOrigin.y, width, color);
}

void CGDrawingContext::drawRect(CGRect rect, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->drawRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, color);
}

void CGDrawingContext::drawRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->drawRoundRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, roundness,
                           color);
}

void CGDrawingContext::drawCircle(CGPoint center, CGInt radius, CGColor color) {
  auto absCenter = convertToAbsolute(center);
  _drawable->drawCircle(absCenter.x, absCenter.y, radius, color);
}

void CGDrawingContext::drawString(String string, CGPoint position) {
  auto absPosition = convertToAbsolute(position);
  _drawable->drawString(string, absPosition.x, absPosition.y);
}

void CGDrawingContext::fill(CGColor color) {
  if (_inMemory) {
    ((TFT_eSprite *)_drawable)->fillSprite(color);
  } else {
    _drawable->fillScreen(color);
  }
}

void CGDrawingContext::fillRect(CGRect rect, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->fillRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, color);
}

void CGDrawingContext::fillRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  auto absRect = convertToAbsolute(rect);
  _drawable->fillRoundRect(absRect.origin.x, absRect.origin.y, absRect.size.width, absRect.size.height, roundness,
                           color);
}

void CGDrawingContext::fillCircle(CGPoint center, CGInt radius, CGColor color) {
  auto absCenter = convertToAbsolute(center);
  _drawable->fillCircle(absCenter.x, absCenter.y, radius, color);
}
