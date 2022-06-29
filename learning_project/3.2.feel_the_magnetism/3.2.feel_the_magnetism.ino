int reedPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(reedPin, INPUT);
}

void loop() {
  Serial.println(digitalRead(reedPin));
  delay(10);       
}
