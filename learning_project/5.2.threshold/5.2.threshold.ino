const int soilMoisture = A0;
const int redPin = 11;  // R petal onmodule connected to digital pin 11
const int greenPin = 9;  // B petal onmodule connected to digital pin 9

int threshold = 900;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(soilMoisture);
  Serial.println(sensorValue);
  if (sensorValue > threshold) {
    digitalWrite(redPin, HIGH); // Turn the red LED
    digitalWrite(greenPin, LOW); // green
  } else {
    digitalWrite(greenPin, HIGH); // Turn on the green LED
    digitalWrite(redPin, LOW); // red
  }
}
