#include "TFTBitmap.h"

#include "TFTDisplay.h"
#include "TFTUtils.h"

TFTBitmap::TFTBitmap(CGSize size, CGColorDepth colorDepth, bool allocImmediately) : CGBitmap() {
  _bounds = CGRect(CGPointZero, size);
  _colorDepth = colorDepth;

  _nativeSprite = new TFT_eSprite(TFTDisplay::instance()->nativeTFT());

  if (allocImmediately) {
    alloc();
  }
}

TFTBitmap::~TFTBitmap() {
  free();
  delete _nativeSprite;
}

CGFontFamily TFTBitmap::fontFamily() {
  return _fontFamily;
}

void TFTBitmap::fontFamily(CGFontFamily value) {
  _fontFamily = value;
  TFTUtils::setFontFamily(_nativeSprite, _fontFamily);
}

uint8_t TFTBitmap::fontSize() {
  return _fontSize;
}

void TFTBitmap::fontSize(uint8_t value) {
  _fontSize = value;
  _nativeSprite->setTextSize(_fontSize);
}

CGColor TFTBitmap::textColor() {
  return _textColor;
}

void TFTBitmap::textColor(CGColor value) {
  _textColor = value;
  _nativeSprite->setTextColor(value);
}

CGTextAlign TFTBitmap::textAlign() {
  return _textAlign;
}

void TFTBitmap::textAlign(CGTextAlign value) {
  _textAlign = value;
  _updateTextDatum();
}

CGTextBaseline TFTBitmap::textBaseline() {
  return _textBaseline;
}

void TFTBitmap::textBaseline(CGTextBaseline value) {
  _textBaseline = value;
  _updateTextDatum();
}

void TFTBitmap::alloc() {
  _nativeSprite->setColorDepth((int8_t)_colorDepth);
  _nativeSprite->createSprite(size().width, size().height);
  fontFamily(_fontFamily);
  fontSize(_fontSize);
  textAlign(_textAlign);
  textBaseline(_textBaseline);
  textColor(_textColor);
}

void TFTBitmap::free() {
  _nativeSprite->deleteSprite();
}

uint8_t *TFTBitmap::to8BitArray() {
  return (uint8_t *)_nativeSprite->frameBuffer(1);
}

uint16_t *TFTBitmap::to16BitArray() {
  return (uint16_t *)_nativeSprite->frameBuffer(1);
}

void TFTBitmap::drawPixel(CGPoint point, CGColor color) {
  _nativeSprite->drawPixel(point.x, point.y, color);
}

void TFTBitmap::drawLine(CGPoint p1, CGPoint p2, CGColor color) {
  _nativeSprite->drawLine(p1.x, p1.y, p2.x, p2.y, color);
}

void TFTBitmap::drawFastVLine(CGPoint origin, CGInt height, CGColor color) {
  _nativeSprite->drawFastVLine(origin.x, origin.y, height, color);
}

void TFTBitmap::drawFastHLine(CGPoint origin, CGInt width, CGColor color) {
  _nativeSprite->drawFastHLine(origin.x, origin.y, width, color);
}

void TFTBitmap::drawRect(CGRect rect, CGColor color) {
  _nativeSprite->drawRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, color);
}

void TFTBitmap::drawRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  _nativeSprite->drawRoundRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, roundness, color);
}

void TFTBitmap::drawCircle(CGPoint center, CGInt radius, CGColor color) {
  _nativeSprite->drawCircle(center.x, center.y, radius, color);
}

void TFTBitmap::drawString(String string, CGPoint position) {
  _nativeSprite->drawString(string, position.x, position.y);
}

void TFTBitmap::drawBitmap(CGBitmap *bitmap, CGPoint position) {
  if (bitmap->colorDepth() == CGColorDepth::BIT_16) {
    _nativeSprite->pushImage(position.x, position.y, bitmap->size().width, bitmap->size().height,
                             bitmap->to16BitArray());
  } else {
    // Not supported.
  }
}

void TFTBitmap::drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor) {
  // Not supported.
  drawBitmap(bitmap, position);
}

void TFTBitmap::drawXBM(CGXBM *xbm, CGPoint position, CGColor color) {
  _nativeSprite->drawXBitmap(position.x, position.y, xbm->data(), xbm->size().width, xbm->size().height, color);
}

void TFTBitmap::fill(CGColor color) {
  _nativeSprite->fillSprite(color);
}

void TFTBitmap::fillRect(CGRect rect, CGColor color) {
  _nativeSprite->fillRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, color);
}

void TFTBitmap::fillRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  _nativeSprite->fillRoundRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, roundness, color);
}

void TFTBitmap::fillCircle(CGPoint center, CGInt radius, CGColor color) {
  _nativeSprite->fillCircle(center.x, center.y, radius, color);
}

void TFTBitmap::_updateTextDatum() {
  TFTUtils::setTextDatum(_nativeSprite, _textAlign, _textBaseline);
}
