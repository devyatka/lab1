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

bool start = false;
int notes[] = {NOTE_G3};
double durations[] = {8};
int melodyLength = 1;

void setup() {
    Serial.begin(115200);
    buzzer1.setMelody(notes, durations, melodyLength);
    buzzer1.turnSoundOn();
    buzzer2.setMelody(notes, durations, melodyLength);
    buzzer2.turnSoundOn();
    buzzer3.setMelody(notes, durations, melodyLength);
    buzzer3.turnSoundOn();
    buzzer4.setMelody(notes, durations, melodyLength);
    buzzer4.turnSoundOn();

}

void loop() {

    if (buttonOn.wasPressed()){
      start = true;
    }

    if (start){

      Buzzer buzzers[] = {buzzer1, buzzer2, buzzer3, buzzer4};
  
      for(int i = 0; i < 5; i++){
        Serial.write(i);
        buzzers[i % 4].playSound();
        delay(1000);
        buzzers[i % 4].turnSoundOff();
      }
    }
    
}
