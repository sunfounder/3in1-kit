const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  for(int i=0;i<=255;i+=5){
    moveForward(i);
    delay(500);
  }
  for(int i=255;i>=0;i-=5){
    moveForward(i);
    delay(500);
  }
}

void moveForward(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
}
