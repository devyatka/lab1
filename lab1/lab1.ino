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
Buzzer buzzer1(PIN_BUZZER1);
Buzzer buzzer2(PIN_BUZZER2);
Buzzer buzzer3(PIN_BUZZER3);
Buzzer buzzer4(PIN_BUZZER4);
Buzzer buzzers[] = {buzzer1, buzzer2, buzzer3, buzzer4};

bool start = false;
int notes1[] = {NOTE_G3};
int notes2[] = {NOTE_A2};
double durations[] = {8};
int melodyLength = 1;
int currentBuzzer = 0;
int soundDuration = 1000;
uint64_t lastMillis;

void setup() {
    buzzers[0].setMelody(notes1, durations, melodyLength);
    buzzers[1].setMelody(notes2, durations, melodyLength);
    buzzers[2].setMelody(notes1, durations, melodyLength);
    buzzers[3].setMelody(notes2, durations, melodyLength);
}

void loop() {

    if (buttonOn.wasPressed()){
      start = true;
      buzzers[currentBuzzer].turnSoundOn();
      lastMillis = millis();
    }

    if (start){
      buzzers[currentBuzzer % 4].playSound();
      if ((millis() - lastMillis) > soundDuration){
        buzzers[currentBuzzer % 4].turnSoundOff();
        currentBuzzer++;
        buzzers[currentBuzzer % 4].turnSoundOn();
        lastMillis = millis();
      }
    }
    
}
