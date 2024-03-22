#include <Arduino.h>
#include <M5StickCPlus2.h>

#include "SoundController.h"

#define SPEAKER M5.Speaker
#define NOTE_G5  784
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define REST      0
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C7  2093
#define NOTE_D7  2349

int tempo = 200;

int wholenote = (60000 * 4) / tempo;

int melodyReady[] = {
  NOTE_E6,8, NOTE_G6,8, REST,4,
  REST,4 
};

int melodyAlert[] = {
  NOTE_G6,8, NOTE_E6,8, NOTE_G6,8,
  REST,4 
};

int melodyOk[] = {
  NOTE_G6,4, NOTE_E6,4,
  REST,4
};

int melodyError[] = {
  NOTE_E6,4, REST,8, NOTE_E6,4,
  REST,4 
};

void SoundController::playMelody(int melody[], int melodySize) {
  int noteDuration;
  int divider;

  for (int thisNote = 0; thisNote < melodySize; thisNote += 2) {
    divider = melody[thisNote + 1];

    if (divider > 0) {
      noteDuration = wholenote / divider;

    } else if (divider < 0) {
      noteDuration = wholenote / -divider;
      noteDuration *= 1.5;
    }

    SPEAKER.tone(melody[thisNote]*4, noteDuration * 0.9);
    SPEAKER.tone(0, noteDuration*0.1);
    delay(noteDuration);
    SPEAKER.stop(); 
  }
  delay(noteDuration / 2);
}

void SoundController::playReady() {
  SoundController::playMelody(melodyReady, sizeof(melodyReady) / sizeof(melodyReady[0]));
}

void SoundController::playAlert() {
  SoundController::playMelody(melodyAlert, sizeof(melodyAlert) / sizeof(melodyAlert[0]));
}

void SoundController::playOk() {
  SoundController::playMelody(melodyOk, sizeof(melodyOk) / sizeof(melodyOk[0]));
}

void SoundController::playError() {
  SoundController::playMelody(melodyError, sizeof(melodyError) / sizeof(melodyError[0]));
}
