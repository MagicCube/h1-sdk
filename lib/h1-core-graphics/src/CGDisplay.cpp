#include "CGDisplay.h"

CGDisplayClass::CGDisplayClass() {
  _nativeTFT = new TFT_eSPI();
}

CGRect CGDisplayClass::bounds() {
  return _bounds;
}

CGSize CGDisplayClass::size() {
  return _bounds.size;
}

TFT_eSPI *CGDisplayClass::nativeTFT() {
  return _nativeTFT;
}

void CGDisplayClass::begin() {
  _nativeTFT->begin();
}

CGDisplayClass CGDisplay;
