#include <Arduino.h>
#include <Wire.h>
#include <M5StickCPlus2.h>
// #include "rfid2/RFIDController.h"
#include "RFIDController.h"
// #include "rfid2/DisplayController.h"
#include "DisplayController.h"
// #include "rfid2/SoundController.h"
#include "SoundController.h"
// #include "rfid2/StateController.h"
#include "StateController.h"
// #include "rfid2/Global.h"
#include "Global.h"
// #include "rfid2/MFRC522_I2C.h"
#include "MFRC522_I2C.h"

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

