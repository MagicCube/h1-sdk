#pragma once

#include <Arduino.h>
#include <memory>
#include <stdarg.h>

using namespace std;

// Output a debug log to serial with [formatString](https://alvinalexander.com/programming/printf-format-cheat-sheet).
inline void LOG_I(const string formatString, ...) {
  Serial.print("[INF] ");
  int final_n, n = ((int)formatString.size()) * 2; /* Reserve two times as much as the length of the formatString */
  unique_ptr<char[]> formatted;
  va_list ap;
  while (1) {
    formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
    strcpy(&formatted[0], formatString.c_str());
    va_start(ap, formatString);
    final_n = vsnprintf(&formatted[0], n, formatString.c_str(), ap);
    va_end(ap);
    if (final_n < 0 || final_n >= n) {
      n += abs(final_n - n + 1);
    } else {
      break;
    }
  }
  Serial.println(formatted.get());
}

// Output a debug log to serial with [formatString](https://alvinalexander.com/programming/printf-format-cheat-sheet).
inline void LOG_D(const string formatString, ...) {
#ifdef DEBUG
  Serial.print("[DBG] ");
  int final_n, n = ((int)formatString.size()) * 2; /* Reserve two times as much as the length of the formatString */
  unique_ptr<char[]> formatted;
  va_list ap;
  while (1) {
    formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
    strcpy(&formatted[0], formatString.c_str());
    va_start(ap, formatString);
    final_n = vsnprintf(&formatted[0], n, formatString.c_str(), ap);
    va_end(ap);
    if (final_n < 0 || final_n >= n) {
      n += abs(final_n - n + 1);
    } else {
      break;
    }
  }
  Serial.println(formatted.get());
#endif
}
