#include <Wire.h>
#include <Arduino.h>
#include "RFIDController.h"
#include "DisplayController.h"
#include "SoundController.h"
#include "Global.h"
#include "MFRC522_I2C.h"

MFRC522 mfrc522(0x28);

void RFIDController::initialize() {
  mfrc522.PCD_Init();
}

void RFIDController::readCard() {
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  DisplayController::displayCardInfo(mfrc522.PICC_GetTypeName(piccType));
  const char ERROR_MESSAGE[] = "Not MIFARE Classic!";
  
  if (!(piccType == MFRC522::PICC_TYPE_MIFARE_MINI ||
        piccType == MFRC522::PICC_TYPE_MIFARE_1K ||
        piccType == MFRC522::PICC_TYPE_MIFARE_4K)) {
      DisplayController::displayErrorMessage(ERROR_MESSAGE);
    SoundController::playError();
    delay(1000);
  } else {
    readUID = true;
    UIDLength = mfrc522.uid.size;
    for (byte i = 0; i < UIDLength; i++) {
      UID[i] = mfrc522.uid.uidByte[i];
    }
    Serial.println();
    DisplayController::displayUID();
    SoundController::playAlert();
    delay(1000);
  }
}

void RFIDController::writeCard() {
if (mfrc522.MIFARE_SetUid(UID, (byte)UIDLength, true)) {
    DisplayController::displayMessageAndSound(F("Wrote UID."), true);
  } else {
    DisplayController::displayMessageAndSound(F("Write failed."), false);
  }

  mfrc522.PICC_HaltA();
  delay(1000);
}

void RFIDController::handleCardDetection() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return; 
  }
  
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  DisplayController::cls();

  switch (currentState) {
    case READ_MODE:
      RFIDController::readCard();
      break;
    case WRITE_MODE:
      RFIDController::writeCard();
      break;
  }
}
