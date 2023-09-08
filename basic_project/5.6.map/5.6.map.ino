#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int servoPin = 9;
const int knob = A0;  // analog pin used to connect the potentiometer

void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int value = analogRead(knob);            // reads the value of the potentiometer (value between 0 and 1023)
  int angle = map(value, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(angle);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
