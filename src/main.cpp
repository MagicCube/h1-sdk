#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

#include "AppDelegate.h"

AppDelegate appDelegate;

void setup() {
  Serial.begin(115200);

  UIScreen.rotation(3);
  UIScreen.begin();
  UIScreen.clear();

  UIApplication.delegate(&appDelegate);
  UIApplication.begin();
}

void loop() {
  UIApplication.loop();
}
