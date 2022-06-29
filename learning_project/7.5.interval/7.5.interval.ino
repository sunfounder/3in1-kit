#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0,NOTE_B3, NOTE_C4,0
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4,2
};

const int buzzerPin =  9;
unsigned long previousMillis = 0;        // will store last time tone

int thisNote=0; 
long interval=1000;

const int ledPin=8;
const int buttonPin=2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // play music
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;// save the time of the last tone
    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // interval at which to tone
    thisNote=(thisNote+1)%(sizeof(melody)/2); //iterate over the notes of the melody
  }

  // play button & led 
  digitalWrite(ledPin,digitalRead(buttonPin));

}
