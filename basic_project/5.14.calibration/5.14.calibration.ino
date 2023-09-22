const int buzzerPin = 9;
const int ledPin = 8;
const int photocellPin = A0;  //photoresistor attach to A2

int lightLow = 1023;
int lightHigh = 0;

int sensorValue = 0;        // value read from the sensor
int pitch = 0;           // sensor value converted into LED 'bars'

unsigned long previousMillis = 0;
const long interval = 5000;

void setup()
{
  pinMode(buzzerPin, OUTPUT); // make buzzer output
  pinMode(ledPin, OUTPUT); // make the LED pin output

  /* calibrate the photoresistor max & min values */
  previousMillis = millis();
  digitalWrite(ledPin, HIGH);
  while (millis() - previousMillis <= interval) {
    sensorValue = analogRead(photocellPin);
    if (sensorValue > lightHigh) {
      lightHigh = sensorValue;
    }
    if (sensorValue < lightLow) {
      lightLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop()
{
  /* play*/
  sensorValue = analogRead(photocellPin); //read the value of A0
  pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // map to the buzzer frequency
  if (pitch > 50) {
    tone(buzzerPin, pitch, 20);
  }
  delay(10);
}
