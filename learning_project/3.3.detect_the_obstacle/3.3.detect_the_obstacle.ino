int irObstaclePin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(irObstaclePin, INPUT);
}

void loop() {
  Serial.println(digitalRead(irObstaclePin));
  delay(10);       
}
