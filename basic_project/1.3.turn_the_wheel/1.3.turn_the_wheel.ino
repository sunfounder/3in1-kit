
const int B_1A = 9;
const int B_1B = 10;

void setup()
{
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
}

void loop()
{
  digitalWrite(B_1A, HIGH);
  digitalWrite(B_1B, LOW);
  delay(2000);

  digitalWrite(B_1A, LOW);
  digitalWrite(B_1B, LOW);
  delay(500);

  digitalWrite(B_1A, LOW);
  digitalWrite(B_1B, HIGH);
  delay(2000);

  digitalWrite(B_1A, LOW);
  digitalWrite(B_1B, LOW);
  delay(500);
}
