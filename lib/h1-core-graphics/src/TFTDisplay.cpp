#include "TFTDisplay.h"

static TFTDisplay *__instance;

TFTDisplay::TFTDisplay() : _bounds(CGPointZero, TFT_WIDTH, TFT_HEIGHT) {
  _nativeDisplay = new TFT_eSPI();
  __instance = this;
}

TFTDisplay *TFTDisplay::instance() {
  return __instance;
}

void TFTDisplay::rotation(uint8_t rotation) {
  _nativeDisplay->setRotation(rotation);
}

CGFontFamily TFTDisplay::fontFamily() {
  return _fontFamily;
}

void TFTDisplay::fontFamily(CGFontFamily value) {
  _fontFamily = value;
  uint8_t _fontFamilyValue = (uint8_t)_fontFamily;
  if (_fontFamilyValue < 10) {
    // Basic font
    _nativeDisplay->setFreeFont(nullptr);
    _nativeDisplay->setTextFont(_fontFamilyValue);
  } else if (_fontFamilyValue < 60) {
    switch (value) {
    case CGFontFamily::FREE_MONO_9PT:
      _nativeDisplay->setFreeFont(&FreeMono9pt7b);
      break;
    case CGFontFamily::FREE_MONO_12PT:
      _nativeDisplay->setFreeFont(&FreeMono12pt7b);
      break;
    case CGFontFamily::FREE_MONO_18PT:
      _nativeDisplay->setFreeFont(&FreeMono18pt7b);
      break;
    case CGFontFamily::FREE_MONO_24PT:
      _nativeDisplay->setFreeFont(&FreeMono24pt7b);
      break;
    case CGFontFamily::FREE_SANS_9PT:
      _nativeDisplay->setFreeFont(&FreeSans9pt7b);
      break;
    case CGFontFamily::FREE_SANS_12PT:
      _nativeDisplay->setFreeFont(&FreeSans12pt7b);
      break;
    case CGFontFamily::FREE_SANS_18PT:
      _nativeDisplay->setFreeFont(&FreeSans18pt7b);
      break;
    case CGFontFamily::FREE_SANS_24PT:
      _nativeDisplay->setFreeFont(&FreeSans24pt7b);
      break;
    case CGFontFamily::FREE_SERIF_9PT:
      _nativeDisplay->setFreeFont(&FreeSerif9pt7b);
      break;
    case CGFontFamily::FREE_SERIF_BOLD_9PT:
      _nativeDisplay->setFreeFont(&FreeSerifBold9pt7b);
      break;
    case CGFontFamily::FREE_SERIF_12PT:
      _nativeDisplay->setFreeFont(&FreeSerif12pt7b);
      break;
    case CGFontFamily::FREE_SERIF_BOLD_12PT:
      _nativeDisplay->setFreeFont(&FreeSerifBold12pt7b);
      break;
    case CGFontFamily::FREE_SERIF_18PT:
      _nativeDisplay->setFreeFont(&FreeSerif18pt7b);
      break;
    case CGFontFamily::FREE_SERIF_BOLD_18PT:
      _nativeDisplay->setFreeFont(&FreeSerifBold18pt7b);
      break;
    case CGFontFamily::FREE_SERIF_24PT:
      _nativeDisplay->setFreeFont(&FreeSerif24pt7b);
      break;
    case CGFontFamily::FREE_SERIF_BOLD_24PT:
      _nativeDisplay->setFreeFont(&FreeSerifBold24pt7b);
      break;
    default:
      break;
    }
  }
}

uint8_t TFTDisplay::fontSize() {
  return _fontSize;
}

void TFTDisplay::fontSize(uint8_t value) {
  _fontSize = value;
  _nativeDisplay->setTextSize(_fontSize);
}

CGColor TFTDisplay::textColor() {
  return _textColor;
}

void TFTDisplay::textColor(CGColor value) {
  _textColor = value;
  _nativeDisplay->setTextColor(value);
}

CGTextAlign TFTDisplay::textAlign() {
  return _textAlign;
}

void TFTDisplay::textAlign(CGTextAlign value) {
  _textAlign = value;
  _updateTextDatum();
}

CGTextBaseline TFTDisplay::textBaseline() {
  return _textBaseline;
}

void TFTDisplay::textBaseline(CGTextBaseline value) {
  _textBaseline = value;
  _updateTextDatum();
}

void TFTDisplay::begin() {
  _nativeDisplay->begin();

  fontFamily(_fontFamily);
  fontSize(_fontSize);
  textAlign(_textAlign);
  textBaseline(_textBaseline);
  textColor(_textColor);
}

void TFTDisplay::drawPixel(CGPoint point, CGColor color) {
  _nativeDisplay->drawPixel(point.x, point.y, color);
}

void TFTDisplay::drawLine(CGPoint p1, CGPoint p2, CGColor color) {
  _nativeDisplay->drawLine(p1.x, p1.y, p2.x, p2.y, color);
}

void TFTDisplay::drawFastVLine(CGPoint origin, CGInt height, CGColor color) {
  _nativeDisplay->drawFastVLine(origin.x, origin.y, height, color);
}

void TFTDisplay::drawFastHLine(CGPoint origin, CGInt width, CGColor color) {
  _nativeDisplay->drawFastHLine(origin.x, origin.y, width, color);
}

void TFTDisplay::drawRect(CGRect rect, CGColor color) {
  _nativeDisplay->drawRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, color);
}

void TFTDisplay::drawRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  _nativeDisplay->drawRoundRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, roundness, color);
}

void TFTDisplay::drawCircle(CGPoint center, CGInt radius, CGColor color) {
  _nativeDisplay->drawCircle(center.x, center.y, radius, color);
}

void TFTDisplay::drawString(String string, CGPoint position) {
  _nativeDisplay->drawString(string, position.x, position.y);
}

void TFTDisplay::drawBitmap(CGBitmap *bitmap, CGPoint position) {
  if (bitmap->colorDepth() == CGColorDepth::BIT_16) {
    _nativeDisplay->pushImage(position.x, position.y, bitmap->size().width, bitmap->size().height,
                              bitmap->to16BitArray());
  } else {
    _nativeDisplay->pushImage(position.x, position.y, bitmap->size().width, bitmap->size().height,
                              bitmap->to8BitArray(), bitmap->colorDepth() == CGColorDepth::BIT_8);
  }
}

void TFTDisplay::drawBitmap(CGBitmap *bitmap, CGPoint position, CGColor transparentColor) {
  if (bitmap->colorDepth() == CGColorDepth::BIT_16) {
    _nativeDisplay->pushImage(position.x, position.y, bitmap->size().width, bitmap->size().height,
                              bitmap->to16BitArray(), transparentColor);
  } else {
    _nativeDisplay->pushImage(position.x, position.y, bitmap->size().width, bitmap->size().height,
                              bitmap->to8BitArray(), transparentColor, bitmap->colorDepth() == CGColorDepth::BIT_8);
  }
}

void TFTDisplay::drawXBM(CGXBM *xbm, CGPoint position, CGColor color) {
  _nativeDisplay->drawXBitmap(position.x, position.y, xbm->data(), xbm->size().width, xbm->size().height, color);
}

void TFTDisplay::fill(CGColor color) {
  _nativeDisplay->fillScreen(color);
}

void TFTDisplay::fillRect(CGRect rect, CGColor color) {
  _nativeDisplay->fillRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, color);
}

void TFTDisplay::fillRoundRect(CGRect rect, CGInt roundness, CGColor color) {
  _nativeDisplay->fillRoundRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, roundness, color);
}

void TFTDisplay::fillCircle(CGPoint center, CGInt radius, CGColor color) {
  _nativeDisplay->fillCircle(center.x, center.y, radius, color);
}

void TFTDisplay::_updateTextDatum() {
  if (_textAlign == CGTextAlign::LEFT) {
    switch (_textBaseline) {
    case CGTextBaseline::TOP:
      _nativeDisplay->setTextDatum(TL_DATUM);
      break;
    case CGTextBaseline::MIDDLE:
      _nativeDisplay->setTextDatum(ML_DATUM);
      break;
    case CGTextBaseline::BOTTOM:
      _nativeDisplay->setTextDatum(BL_DATUM);
      break;
    }
  } else if (_textAlign == CGTextAlign::CENTER) {
    switch (_textBaseline) {
    case CGTextBaseline::TOP:
      _nativeDisplay->setTextDatum(TC_DATUM);
      break;
    case CGTextBaseline::MIDDLE:
      _nativeDisplay->setTextDatum(MC_DATUM);
      break;
    case CGTextBaseline::BOTTOM:
      _nativeDisplay->setTextDatum(BC_DATUM);
      break;
    }
  } else if (_textAlign == CGTextAlign::RIGHT) {
    switch (_textBaseline) {
    case CGTextBaseline::TOP:
      _nativeDisplay->setTextDatum(TR_DATUM);
      break;
    case CGTextBaseline::MIDDLE:
      _nativeDisplay->setTextDatum(MR_DATUM);
      break;
    case CGTextBaseline::BOTTOM:
      _nativeDisplay->setTextDatum(BR_DATUM);
      break;
    }
  }
}
