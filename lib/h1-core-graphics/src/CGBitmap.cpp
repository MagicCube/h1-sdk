#include "CGBitmap.h"

#include "CGDisplay.h"

CGBitmap::CGBitmap(CGSize size, CGColorDepth colorDepth) {
  _bounds = CGRect(CGPointZero, size);
  _colorDepth = colorDepth;

  _sprite = new TFT_eSprite(CGDisplay.nativeTFT());
  _sprite->setColorDepth((int8_t)_colorDepth);
  alloc();
}

CGBitmap::~CGBitmap() {
  free();
  delete _sprite;
}

CGRect CGBitmap::bounds() {
  return _bounds;
}

CGSize CGBitmap::size() {
  return _bounds.size;
}

CGColorDepth CGBitmap::colorDepth() {
  return _colorDepth;
}

CGDrawingContext *CGBitmap::createDrawingContext() {
  CGDrawingContext *drawingContext = new CGDrawingContext(_sprite, size(), true);
  return drawingContext;
}

void CGBitmap::alloc() {
  _sprite->createSprite(size().width, size().height);
}

void CGBitmap::free() {
  _sprite->deleteSprite();
}
