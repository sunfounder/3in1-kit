int grayscalePin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(grayscalePin, INPUT);
}

void loop() {
  Serial.println(digitalRead(grayscalePin));
  delay(10);       
}
