#pragma once

#include "Arduino.h"

enum class DurationFormat { HH_MM_SS, MM_SS };

inline String formatDuration(unsigned long duration, DurationFormat format = DurationFormat::HH_MM_SS) {
  auto totalSeconds = duration / 1000;
  uint16_t minutes = totalSeconds / 60;
  uint8_t seconds = totalSeconds % 60;
  if (format == DurationFormat::HH_MM_SS) {
    char result[8];
    sprintf(result, "%02d:%02d:%02d", minutes / 60, minutes % 60, seconds);
    return String(result);
  } else {
    char result[5];
    sprintf(result, "%02d:%02d", minutes, seconds);
    return String(result);
  }
}
