#include "CGDisplay.h"

CGDisplayClass::CGDisplayClass() {
  _nativeTFT = new TFT_eSPI();
}

TFT_eSPI *CGDisplayClass::nativeTFT() {
  return _nativeTFT;
}

void CGDisplayClass::begin() {
  _nativeTFT->begin();
}

CGDisplayClass CGDisplay;
