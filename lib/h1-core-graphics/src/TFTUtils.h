#pragma once

#include <Arduino.h>

#include <TFT_eSPI.h>

#include "CGFont.h"
#include "types.h"

class TFTUtils {
public:
  static void setFontFamily(TFT_eSPI *nativeTFT, CGFontFamily value) {
    uint8_t fontFamilyValue = (uint8_t)value;
    if (fontFamilyValue < 10) {
      // Basic font
      nativeTFT->setFreeFont(nullptr);
      nativeTFT->setTextFont(fontFamilyValue);
    } else if (fontFamilyValue < 60) {
      switch (value) {
      case CGFontFamily::FREE_MONO_9PT:
        nativeTFT->setFreeFont(&FreeMono9pt7b);
        break;
      case CGFontFamily::FREE_MONO_12PT:
        nativeTFT->setFreeFont(&FreeMono12pt7b);
        break;
      case CGFontFamily::FREE_MONO_18PT:
        nativeTFT->setFreeFont(&FreeMono18pt7b);
        break;
      case CGFontFamily::FREE_MONO_24PT:
        nativeTFT->setFreeFont(&FreeMono24pt7b);
        break;
      case CGFontFamily::FREE_SANS_9PT:
        nativeTFT->setFreeFont(&FreeSans9pt7b);
        break;
      case CGFontFamily::FREE_SANS_12PT:
        nativeTFT->setFreeFont(&FreeSans12pt7b);
        break;
      case CGFontFamily::FREE_SANS_18PT:
        nativeTFT->setFreeFont(&FreeSans18pt7b);
        break;
      case CGFontFamily::FREE_SANS_24PT:
        nativeTFT->setFreeFont(&FreeSans24pt7b);
        break;
      case CGFontFamily::FREE_SERIF_9PT:
        nativeTFT->setFreeFont(&FreeSerif9pt7b);
        break;
      case CGFontFamily::FREE_SERIF_BOLD_9PT:
        nativeTFT->setFreeFont(&FreeSerifBold9pt7b);
        break;
      case CGFontFamily::FREE_SERIF_12PT:
        nativeTFT->setFreeFont(&FreeSerif12pt7b);
        break;
      case CGFontFamily::FREE_SERIF_BOLD_12PT:
        nativeTFT->setFreeFont(&FreeSerifBold12pt7b);
        break;
      case CGFontFamily::FREE_SERIF_18PT:
        nativeTFT->setFreeFont(&FreeSerif18pt7b);
        break;
      case CGFontFamily::FREE_SERIF_BOLD_18PT:
        nativeTFT->setFreeFont(&FreeSerifBold18pt7b);
        break;
      case CGFontFamily::FREE_SERIF_24PT:
        nativeTFT->setFreeFont(&FreeSerif24pt7b);
        break;
      case CGFontFamily::FREE_SERIF_BOLD_24PT:
        nativeTFT->setFreeFont(&FreeSerifBold24pt7b);
        break;
      default:
        break;
      }
    }
  }

  static void setTextDatum(TFT_eSPI *nativeTFT, CGTextAlign textAlign, CGTextBaseline textBaseline) {
    if (textAlign == CGTextAlign::LEFT) {
      switch (textBaseline) {
      case CGTextBaseline::TOP:
        nativeTFT->setTextDatum(TL_DATUM);
        break;
      case CGTextBaseline::MIDDLE:
        nativeTFT->setTextDatum(ML_DATUM);
        break;
      case CGTextBaseline::BOTTOM:
        nativeTFT->setTextDatum(BL_DATUM);
        break;
      }
    } else if (textAlign == CGTextAlign::CENTER) {
      switch (textBaseline) {
      case CGTextBaseline::TOP:
        nativeTFT->setTextDatum(TC_DATUM);
        break;
      case CGTextBaseline::MIDDLE:
        nativeTFT->setTextDatum(MC_DATUM);
        break;
      case CGTextBaseline::BOTTOM:
        nativeTFT->setTextDatum(BC_DATUM);
        break;
      }
    } else if (textAlign == CGTextAlign::RIGHT) {
      switch (textBaseline) {
      case CGTextBaseline::TOP:
        nativeTFT->setTextDatum(TR_DATUM);
        break;
      case CGTextBaseline::MIDDLE:
        nativeTFT->setTextDatum(MR_DATUM);
        break;
      case CGTextBaseline::BOTTOM:
        nativeTFT->setTextDatum(BR_DATUM);
        break;
      }
    }
  }
};
