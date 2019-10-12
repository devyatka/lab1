#include <Arduino.h>
#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUZZER 6
#define PIN_BUTTON_OFF 5

Button buttonOff(PIN_BUTTON_OFF);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_G3};
double durations[] = {8};
int melodyLength = 1;

void setup() {
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();
}

void loop() {
  
    buzzer.playSound();
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }
}
