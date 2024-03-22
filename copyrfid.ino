#include <Arduino.h>
#include <Wire.h>

#include <M5StickCPlus2.h>
#include "Root.h"

void setup() {
  M5.begin();
  Serial.begin(115200);
  Wire.begin();
  
  DisplayController::initialize();
  RFIDController::initialize();
  StateController::switchToReadMode();
}

void loop() {
  M5.update();
  StateController::handleStateChange();
  RFIDController::handleCardDetection();
}

