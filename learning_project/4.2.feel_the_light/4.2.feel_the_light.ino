void setup() {
  Serial.begin(9600);
}

// photoresistor to VCC , 10k resistor to GND
// much dark , much low value

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(100);       
}
