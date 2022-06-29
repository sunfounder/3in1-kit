
const int buzzerPin = 8;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  for (i = 0; i < 50; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(3);
  }
  delay(1000);
}
