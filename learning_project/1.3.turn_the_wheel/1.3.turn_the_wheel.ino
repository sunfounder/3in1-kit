
const int motorPinA = 9;
const int motorPinB = 10;

void setup()
{
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop()
{
  digitalWrite(motorPinA, HIGH);
  digitalWrite(motorPinB, LOW);
  delay(2000);

  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, LOW);
  delay(500);

  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, HIGH);
  delay(2000);

  digitalWrite(motorPinA, LOW);
  digitalWrite(motorPinB, LOW);
  delay(500);
}
