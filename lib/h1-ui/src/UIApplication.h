#pragma once

#include <Arduino.h>

#include "conf.h"

#include "UIApplicationDelegate.h"
#include "UIWindow.h"

// A class represents the UI application. The only singleton of the class is `UIApplication`.
class UIApplicationClass {
public:
  static const unsigned long updateInterval = 1000 / FPS;

  // Creates a new instance of `UIApplicationClass`.
  UIApplicationClass();

  // Gets the only instance of `UIWindow`.
  UIWindow *window();

  // Gets the delegate of the application.
  UIApplicationDelegate *delegate();

  // Sets the delegate of the application.
  void delegate(UIApplicationDelegate *delegate);

  // Begins the application event loop.
  void begin();

  // Updates in each iteration.
  unsigned long update();

  // Automatically invoke `update()` at fixed interval.
  void loop();

private:
  unsigned long _lastUpdateTime = 0;

  UIWindow *_window = nullptr;
  UIApplicationDelegate *_delegate = nullptr;

  void _doUpdate();
  void _doRedraw();
};

// The singleton of `UIApplicationClass` which represents the centralized point of control and coordination for apps
// running.
extern UIApplicationClass UIApplication;
