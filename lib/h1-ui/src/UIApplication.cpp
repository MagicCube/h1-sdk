#include "UIApplication.h"

void UIApplicationClass::begin() {
}

unsigned long UIApplicationClass::update() {
  auto updateBeginTime = millis();

  _doUpdate();

  auto elapsedSinceLastUpdate = millis() - _lastUpdateTime;
  _lastUpdateTime = updateBeginTime;
  if (elapsedSinceLastUpdate < updateInterval) {
    return updateInterval - elapsedSinceLastUpdate;
  }
  return 0;
}

void UIApplicationClass::_doUpdate() {
}

UIApplicationClass UIApplication;
