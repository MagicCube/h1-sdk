#include "UIApplication.h"

#include "UIScreen.h"

UIApplicationDelegate *UIApplicationClass::delegate() {
  return _delegate;
}

void UIApplicationClass::delegate(UIApplicationDelegate *d) {
  _delegate = d;
}

void UIApplicationClass::begin() {
  if (_delegate != nullptr) {
    _delegate->applicationDidBegin();
  }
}

unsigned long UIApplicationClass::update() {
  auto updateBeginTime = millis();

  _doUpdate();
  _doRedraw();
  UIScreen.update();

  auto elapsedSinceLastUpdate = millis() - _lastUpdateTime;
  _lastUpdateTime = updateBeginTime;
  if (elapsedSinceLastUpdate < updateInterval) {
    return updateInterval - elapsedSinceLastUpdate;
  }
  return 0;
}

void UIApplicationClass::loop() {
  auto timeBudget = update();
  if (timeBudget > 0) {
    delay(timeBudget);
  }
}

void UIApplicationClass::_doUpdate() {
  if (_delegate != nullptr) {
    _delegate->applicationWillUpdate();
  }
}

void UIApplicationClass::_doRedraw() {
  if (_delegate != nullptr) {
    _delegate->applicationWillRedraw();
  }
}

UIApplicationClass UIApplication;
