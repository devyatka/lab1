#include <Arduino.h>
#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUZZER1 5
#define PIN_BUZZER2 2
#define PIN_BUZZER3 3
#define PIN_BUZZER4 4
#define PIN_BUTTON_ON 6

Button buttonOn(PIN_BUTTON_ON); 
int buzzersPins[] = {PIN_BUZZER1, PIN_BUZZER2, PIN_BUZZER3, PIN_BUZZER4};
int buzzerCount = 4;

bool started = false;
int note = NOTE_G3;
int currentBuzzer = 0;
int soundDuration = 500;
uint64_t lastMillis;

void setup() {
}

void loop() {

    if (buttonOn.wasPressed()){
      if (started) {
        started = false;
        noTone(buzzersPins[currentBuzzer]);
      }
      else {
        started = true;
        lastMillis = millis();
      }
    }

    if (started){
      tone(buzzersPins[currentBuzzer], note);
      if ((millis() - lastMillis) > soundDuration){
        noTone(buzzersPins[currentBuzzer]);
        currentBuzzer = (currentBuzzer + 1) % buzzerCount;
        lastMillis = millis();
      }
    }
}
