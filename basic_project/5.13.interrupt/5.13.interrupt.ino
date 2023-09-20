const byte buzzerPin = 8;
const byte interruptPin = 2;
volatile byte state = LOW;
int count=0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), noisy, CHANGE);
  Serial.begin(9600);
  digitalWrite(buzzerPin, state);
}

void loop() {
  count++;
  Serial.println(count);
  delay(1000);
}

void noisy() {
  state = !state;
  digitalWrite(buzzerPin, state);
}
