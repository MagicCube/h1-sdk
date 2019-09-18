#include <Arduino.h>

#include <h1.CoreFoundation.h>
#include <h1.CoreGraphics.h>
#include <h1.UI.h>

#include "AppDelegate.h"

AppDelegate appDelegate;

void setup() {
  // Setup outputs.
  Serial.begin(115200);

  // Setup screen.
  UIScreen.rotation(3);
  UIScreen.begin();
  UIScreen.clear();

  // Setup application.
  UIApplication.delegate(&appDelegate);
  UIApplication.begin();
}

void loop() {
  // Do NOT put any code in the loop().
  UIApplication.loop();
}
