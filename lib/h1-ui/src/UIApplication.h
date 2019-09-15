#pragma once

#include <Arduino.h>

#define FPS 30

// A class represents the UI application. The only singleton of the class is `UIApplication`.
class UIApplicationClass {
public:
  static const unsigned long updateInterval = 1000 / FPS;

  // Begins the application event loop.
  void begin();

  // Updates in each iteration.
  unsigned long update();

private:
  unsigned long _lastUpdateTime = 0;

  void _doUpdate();
};

// The singleton of `UIApplicationClass` which represents the centralized point of control and coordination for apps
// running.
extern UIApplicationClass UIApplication;
