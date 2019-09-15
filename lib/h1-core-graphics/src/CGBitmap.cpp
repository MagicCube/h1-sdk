#include "CGBitmap.h"

CGBitmap::CGBitmap(CGSize size, CGColorDepth colorDepth) {
  _size = size;
  _colorDepth = colorDepth;
}

CGBitmap::CGBitmap(TFT_eSPI *tft, CGSize size, CGColorDepth colorDepth) : CGBitmap(size, colorDepth) {
  _sprite = new TFT_eSprite(tft);
  _sprite->setColorDepth((int8_t)_colorDepth);
  alloc();
}

CGBitmap::~CGBitmap() {
  free();
  delete _sprite;
}

CGSize CGBitmap::size() {
  return _size;
}

CGColorDepth CGBitmap::colorDepth() {
  return _colorDepth;
}

CGDrawingContext *CGBitmap::createDrawingContext() {
  CGDrawingContext *drawingContext = new CGDrawingContext(_sprite, _size, true);
  return drawingContext;
}

void CGBitmap::alloc() {
  _sprite->createSprite(_size.width, _size.height);
}

void CGBitmap::free() {
  _sprite->deleteSprite();
}
