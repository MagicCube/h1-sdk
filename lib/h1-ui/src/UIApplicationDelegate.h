#pragma once

#include <Arduino.h>

// A delegate for `UIApplication`.
// Please set the delegate of `UIApplication` using `delegate(v)` before `begin()`.
class UIApplicationDelegate {
public:
  virtual void applicationDidBegin() {
  }

  virtual void applicationWillUpdate() {
  }
};
