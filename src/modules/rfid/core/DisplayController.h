#ifndef DISPLAYCONTROLLER_H
#define DISPLAYCONTROLLER_H

class DisplayController {
public:
  static void initialize();
  static void cls();
  static void setupDisplay(uint8_t textSize, uint16_t textColor);
  static void displayRfidMessage(const __FlashStringHelper *message,
                                 uint8_t textSize);
  static void displayBatteryLevel();
  static void displayGradientLine();
  static void displayGradientText(const char *text);
  static void displayHeaderRfid();
  static void displayCardInfo(const __FlashStringHelper *message);
  static void displayErrorMessage(const char message[]);
  static void displayUID();
  static void displayMessageAndSound(const __FlashStringHelper *message,
                                    bool isSuccess);
  static void displayReadMode();
  static void displayWriteMode();

};

#endif
