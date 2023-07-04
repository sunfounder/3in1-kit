#include <SoftwareSerial.h>
SoftwareSerial bleSerial(2, 3); //Rx,Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  bleSerial.begin(115200);
}

void loop() {
  if (bleSerial.available()) {
    Serial.write(bleSerial.read());
  }
  if (Serial.available()) {
    bleSerial.write(Serial.read());
  }
}