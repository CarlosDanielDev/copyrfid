#include <Arduino.h>
#include <M5StickCPlus2.h>

#include "DisplayController.h"
#include "SoundController.h"
#include "../shared/Global.h"
#include "../../../i18n/i18n.h"

const uint8_t DEFAULT_TEXT_SIZE = 2;
const uint8_t DEFAULT_BAT_TEXT_SIZE = 1;
const uint8_t DEFAULT_TITLE_TEXT_SIZE = 3;
const uint8_t DEFAULT_LINE_TEXT_SIZE = 1;
const uint8_t DEFAULT_PERCENT_LENGTH = 4;
const uint8_t DEFAULT_BAT_INFO_LENGTH = 9;
const uint8_t DEFAULT_ROTATION = 3;

const int ERROR_MESSAGE_POSITION_X = 0;
const int ERROR_MESSAGE_POSITION_Y = 80;
const uint16_t ERROR_TEXT_COLOR = RED;
const uint16_t DEFAULT_TEXT_COLOR = GREEN;
const uint16_t VALID_UID_COLOR = BLUE;
const uint16_t WARNING_COLOR = YELLOW;
const uint16_t BACKGROUND_COLOR = BLACK;


void DisplayController::initialize() {
  M5.Lcd.setRotation(DEFAULT_ROTATION); 
  M5.Lcd.fillScreen(BACKGROUND_COLOR); 
  M5.Lcd.setCursor(0, 0); 
  M5.Lcd.setTextSize(DEFAULT_TEXT_SIZE); 
}

void DisplayController::cls() {
  DisplayController::initialize();
}

void DisplayController::setupDisplay(uint8_t textSize, uint16_t textColor) {
  M5.Lcd.setTextSize(textSize);
  M5.Lcd.setTextColor(textColor);
}

void DisplayController::displayRfidMessage(const __FlashStringHelper* message, uint8_t textSize) {
  DisplayController::setupDisplay(textSize, DEFAULT_TEXT_COLOR);
  M5.Lcd.println(message); 
}

void DisplayController::displayBatteryLevel() {
  int batteryLevel = M5.Power.getBatteryLevel(); 

  uint16_t batteryTextColor;
  if (batteryLevel <= 20) {
    batteryTextColor = ERROR_TEXT_COLOR; 
  } else if (batteryLevel <= 50) {
    batteryTextColor = WARNING_COLOR;  
  } else if (batteryLevel <= 80 && batteryLevel > 50) {
    batteryTextColor = VALID_UID_COLOR; 
  } else {
    batteryTextColor = DEFAULT_TEXT_COLOR; 
  }

  M5.Lcd.setTextSize(DEFAULT_BAT_TEXT_SIZE);  
  int batteryStrLen = String(batteryLevel).length() + DEFAULT_PERCENT_LENGTH;
  int x = M5.Lcd.width() - (batteryStrLen * DEFAULT_BAT_INFO_LENGTH); 
  int y = 0; 

  M5.Lcd.setTextColor(batteryTextColor, BACKGROUND_COLOR); 
  M5.Lcd.setCursor(x, y);
  M5.Lcd.printf("Bat: %d%%", batteryLevel); 

  M5.Lcd.setTextColor(DEFAULT_TEXT_COLOR, BACKGROUND_COLOR);

}

void DisplayController::displayGradientText(const char* text) {
  uint16_t colors[] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, MAGENTA};

  int numOfColors = sizeof(colors) / sizeof(colors[0]);
  M5.Lcd.setTextSize(DEFAULT_TITLE_TEXT_SIZE);  
  int x = 0;
  int y = 10; 
  int characterWidth = 18; 

  for (int i = 0; text[i] != '\0'; i++) {
    uint16_t color = colors[i % numOfColors];
    M5.Lcd.setTextColor(color, BACKGROUND_COLOR); 

    M5.Lcd.setCursor(x, y);
    M5.Lcd.print(text[i]);

    x += characterWidth;
  }

  M5.Lcd.setTextColor(WHITE, BLACK);
  DisplayController::displayRfidMessage(F(""), DEFAULT_TITLE_TEXT_SIZE);
}

void DisplayController::displayGradientLine() {
   uint16_t colors[] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, MAGENTA};
  int screenWidth = M5.Lcd.width();
  int characterWidth = 6; 
  int numOfCharacters = screenWidth / characterWidth;
  int charactersPerColor = numOfCharacters / (sizeof(colors) / sizeof(colors[0]));

  M5.Lcd.setTextSize(DEFAULT_LINE_TEXT_SIZE);
  
  int charCount = 0; 
  for (uint16_t color : colors) {
    M5.Lcd.setTextColor(color, BLACK);
    for (int i = 0; i < charactersPerColor; ++i) {
      M5.Lcd.print("-");
      if (++charCount >= numOfCharacters) {
        break; 
      }
    }
    if (charCount >= numOfCharacters) {
      break; 
    }
  }
  M5.Lcd.setTextColor(WHITE, BLACK);   
 DisplayController::displayRfidMessage(F(""), DEFAULT_TEXT_SIZE);
}

void DisplayController::displayHeaderRfid() {
  DisplayController::displayBatteryLevel();
  M5.Lcd.setTextSize(DEFAULT_TITLE_TEXT_SIZE);
  M5.Lcd.setCursor(0, 0);
  DisplayController::displayGradientText("Copyrfid");
  DisplayController::displayGradientLine();
}

void DisplayController::displayErrorMessage(const char message[]) {
  DisplayController::setupDisplay(DEFAULT_TEXT_SIZE, ERROR_TEXT_COLOR);
  M5.Lcd.setCursor(ERROR_MESSAGE_POSITION_X, ERROR_MESSAGE_POSITION_Y);
  M5.Lcd.println(message);
  DisplayController::setupDisplay(DEFAULT_TEXT_SIZE, DEFAULT_TEXT_COLOR); 
}

void DisplayController::displayCardInfo(const __FlashStringHelper* message) {
  M5.Lcd.setTextSize(DEFAULT_TEXT_SIZE);
  M5.Lcd.println(message);
}

void DisplayController::displayUID() {
  DisplayController::setupDisplay(DEFAULT_TEXT_SIZE, VALID_UID_COLOR);
  if(UIDLength > 0 ) {
    M5.Lcd.print(F(TXT_RFID_UID));
    for (byte i = 0; i < UIDLength; i++) {
      if (UID[i] < 0x10) {
        M5.Lcd.print("0");
      }
      M5.Lcd.print(UID[i], HEX);
    }
    M5.Lcd.println();
  }
  DisplayController::setupDisplay(DEFAULT_TEXT_SIZE, DEFAULT_TEXT_COLOR);  
}

void DisplayController::displayReadMode() {
  DisplayController::displayHeaderRfid();
  DisplayController::displayRfidMessage(F(TXT_RFID_PRESS_A_READ), DEFAULT_BAT_TEXT_SIZE);
}

void DisplayController::displayWriteMode() {
  DisplayController::displayHeaderRfid();
  DisplayController::displayRfidMessage(F(TXT_RFID_PRESS_A_WRITE), DEFAULT_BAT_TEXT_SIZE);
  DisplayController::displayUID();
}

void DisplayController::displayMessageAndSound(const __FlashStringHelper* message, bool isSuccess) {
  uint16_t textColor = isSuccess ? VALID_UID_COLOR : ERROR_TEXT_COLOR;
  DisplayController::setupDisplay(DEFAULT_TEXT_SIZE, textColor);
  M5.Lcd.println();
  M5.Lcd.println(message);
  if (isSuccess) {
    SoundController::playOk();
  } else {
    SoundController::playError();
  }
  DisplayController::setupDisplay(DEFAULT_TEXT_SIZE, DEFAULT_TEXT_COLOR); 
}
