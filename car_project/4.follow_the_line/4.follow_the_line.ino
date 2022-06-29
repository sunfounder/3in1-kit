const int in1 = 5; // in1,2 for right motor
const int in2 = 6;
const int in3 = 9; // in3,4 for left motor
const int in4 = 10;

const int lineTrack = 2;

void setup() {
  Serial.begin(9600);

  //motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //line track
  pinMode(lineTrack, INPUT);
}

void loop() {

  int speed = 150;

  int lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
  if (lineColor) {
    moveLeft(speed);
  } else {
    moveRight(speed);
  }
}
void moveLeft(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void moveRight(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
}
