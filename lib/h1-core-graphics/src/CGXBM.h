#pragma once

#include <Arduino.h>

#include "CGSize.h"

// A struct describes an `XBM` format image.
class CGXBM {
public:
  // Creates a new `CGXBM`.
  CGXBM(const uint8_t *data, CGSize size) {
    _data = data;
    _size = size;
  }

  ~CGXBM() {
    delete[] _data;
  }

  // Gets the size of the XBM.
  CGSize size() {
    return _size;
  }

  // Gets the raw data of the XMB.
  const uint8_t *data() {
    return _data;
  }

private:
  const uint8_t *_data;
  CGSize _size;
};
