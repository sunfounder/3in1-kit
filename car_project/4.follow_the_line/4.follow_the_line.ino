const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int lineTrack = 2;

void setup() {
  Serial.begin(9600);

  //motor
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
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
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, 0);
}

void moveRight(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
}
