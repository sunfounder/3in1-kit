const int reedPin = 2;
const int ledPin = 8;
int flag = 0;

void setup() {
  pinMode(reedPin, INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  flag = digitalRead(reedPin);
  if (flag == HIGH) {
    digitalWrite(ledPin,LOW);
  } else{
    digitalWrite(ledPin,HIGH);
  }
}
