#include <Arduino.h>
/*

    "pitches.h" is a library that contains pre-defined melodies and note durations for common musical notes.
    You can use this library to create your own melodies and note durations.
    You may refer to the file "pitches.h" in the same folder to see the available melodies.

*/
#include "pitches.h" 
// Built in BUZZER_PIN 35, it is already defined in ISDDevBoard.h
#define BUZZER_PIN 35

//  notes in melody Jingle Bells
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4
};

// note durations: 4 = quarter note, 8 = eighth note, 2= half note, 1= whole note
int noteDurations[] = {
  8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 2
};

void setup() {

    Serial.begin(115200); 
   

    
}



void loop() {
    /*
        "tone()" is a built-in Arduino function that plays a tone on a buzzer.
        Parameters:
            1. int pin: the pin number where the buzzer is connected
            2. int frequency: the frequency of the tone
            3. int duration: the duration of the tone in milliseconds

        Example:
            tone(BUZZER_PIN, NOTE_C4, 500);
            BUZZER_PIN is the pin number where the buzzer is connected
            NOTE_C4 is the frequency of the tone, it can be found in "pitches.h"
            500 is the duration of the tone in milliseconds
    */
    // Uncomment below for Task 1 and replace ? with code
    
    Serial.println("Playing F4...");
    tone(BUZZER_PIN,NOTE_F4, 500);
    delay(1000);
    noTone(BUZZER_PIN);

    Serial.println("Playing G4...");
    tone(BUZZER_PIN,NOTE_G4, 500);
    delay(1000);
    noTone(BUZZER_PIN);
  
  // Uncomment below for Task 2 and replace ? with code
  
   // Task 2 playing Jingle Bells
    Serial.println("Playing Jingle Bells...");
    // Iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 26 ; thisNote++) {
    // To calculate the note duration, take one second divided by the note type.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN,melody[thisNote],noteDuration);
    // To distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Stop the tone playing:
    noTone(BUZZER_PIN);
  }
  

    



}
