#include <EEPROM.h>

const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;

float leftOffset = 1.0;
float rightOffset = 1.0;

void moveForward(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, int(speed * rightOffset));
  analogWrite(in3, int(speed * leftOffset));
  analogWrite(in4, 0);
}

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  EEPROM.write(0, 100); //write the offset to the left motor
  EEPROM.write(1, 100); //write the offset to the right motor
  leftOffset = EEPROM.read(0) * 0.01; //read the offset
  rightOffset = EEPROM.read(1) * 0.01;//read the offset
}

void loop() {
  moveForward(255);
}
