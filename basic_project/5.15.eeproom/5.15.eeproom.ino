#include <Servo.h>
#include <EEPROM.h>//used to store recorded values

Servo myServo;
float resolution = 1000;//MUST be less than EEPROM.length()
float recordTime = 5; //delay time
bool recording = false;

const int ledPin = 3;
const int buttonPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT); //status led
  pinMode(buttonPin, INPUT); //button
  myServo.attach(9);
  Serial.begin(9600);
  //Serial.println(EEPROM.length());
}

void loop() {
  if (recording == true) {//record
    for (int i = 1; i <= resolution; i++) {
      digitalWrite(ledPin, HIGH); //light status led
      int val = map(analogRead(A0), 0, 1023, 0, 180);
      EEPROM.write(i, val);
      //Serial.println(EEPROM.read(i));
      myServo.write(val);
      delay(recordTime);
    }
    digitalWrite(ledPin, LOW); //turn off status led
    delay(1000);//give time for person
    recording = false;
  }
  else {
    for (int i = 1; i <= resolution; i++) {//playback
      if (digitalRead(buttonPin) == 0) {//stop playback and record new values
        recording = true;
        break;
      }
      int readval = EEPROM.read(i);
      myServo.write(readval);
      //Serial.println(readval);
      delay(recordTime);
    }
    digitalWrite(ledPin, HIGH); //show a new repeat
    delay(100);
    digitalWrite(ledPin, LOW);
  }
}
