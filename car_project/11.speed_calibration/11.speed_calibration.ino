#include <EEPROM.h>

const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

float leftOffset = 1.0;
float rightOffset = 1.0;

void moveForward(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, int(speed * rightOffset));
  analogWrite(B_1B, int(speed * leftOffset));
  analogWrite(B_1A, 0);
}

void setup() {
  Serial.begin(9600);
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  EEPROM.write(0, 100); //write the offset to the left motor
  EEPROM.write(1, 100); //write the offset to the right motor
  leftOffset = EEPROM.read(0) * 0.01; //read the offset
  rightOffset = EEPROM.read(1) * 0.01;//read the offset
}

void loop() {
  moveForward(255);
}
