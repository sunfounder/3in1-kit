#include <IRremote.h>
const int recvPin = 12;
IRrecv irrecv(recvPin);
decode_results results;


const int in1 = 5; // in1,2 for right wheel
const int in2 = 6;
const int in3 = 9; // in3,4 for left wheel
const int in4 = 10;

const int echoPin = 4;
const int trigPin = 3;

const int rightIR = 7;
const int leftIR = 8;

const int lineTrackPin = 2;
const int ledPin = 13;

int speed = 150;
String flag = "NONE";

void setup() {
  Serial.begin(9600);

  //motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //ultrasonic
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  //IR obstacle
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  //Line Track Module
  pinMode(lineTrackPin, INPUT);

  //UR remote
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("REMOTE CONTROL START");

  //LED
  pinMode(ledPin, OUTPUT);
}

void loop() {

  if (irrecv.decode(&results)) {
    //    Serial.println(results.value,HEX);
    String key = decodeKeyValue(results.value);
    if ( key != "ERROR")
    {
      Serial.println(key);
      blinkLED();
      if (key == "+") {
        speed += 50;
        Serial.println(speed);
      } else if (key == "-") {
        speed -= 50;
        Serial.println(speed);
      } else if (key == "2") {
        moveForward(speed);
        delay(1000);
      } else if (key == "1") {
        moveLeft(speed);
      } else if (key == "3") {
        moveRight(speed);
      } else if (key == "4") {
        turnLeft(speed);
      } else if (key == "6") {
        turnRight(speed);
      } else if (key == "7") {
        backLeft(speed);
      } else if (key == "9") {
        backRight(speed);
      } else if (key == "8") {
        moveBackward(speed);
        delay(1000);
      } else if (key == "CYCLE") {
        flag = "LINE";
      } else if (key == "U/SD") {
        flag = "AUTO";
      } else if (key == "0") {
        flag = "NONE";
        stopMove();
      } else if (key == "FORWARD") {
        flag = "ULTR";
      } else if (key == "BACKWARD") {
        flag = "IROB";
      } else if (key == "EQ") {
        flag = "FOLW";
      }

      if (speed >= 255) {
        speed = 255;
      }
      if (speed <= 0) {
        speed = 0;
      }
      delay(500);
      stopMove();
    }

    irrecv.resume(); // Receive the next value
  }
  if (flag == "AUTO") {
    AutoDrive(speed);
  } else if (flag == "LINE") {
    lineTrack(speed);
  } else if (flag == "ULTR") {
    ultrasonicExample(speed);
  } else if (flag == "IROB") {
    irobstacleExample(speed);
  } else if (flag == "FOLW") {
    following(speed);
  }
}


float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00; //Equivalent to (340m/s*1us)/2
  return distance;
}

void moveForward(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
}

void moveBackward(int speed) {
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
}

void turnRight(int speed) {
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
}

void turnLeft(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
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

void backLeft(int speed) {
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void backRight(int speed) {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
}

void stopMove() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void blinkLED() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
}


void AutoDrive(int speed) {
  int left = digitalRead(leftIR);  // 0: Obstructed   1: Empty
  int right = digitalRead(rightIR);

  if (!left && right) {
    backLeft(speed);
  } else if (left && !right) {
    backRight(speed);
  } else if (!left && !right) {
    moveBackward(speed);
  } else {
    float distance = readSensorData();
    Serial.println(distance);
    if (distance > 50) { // Safe
      moveForward(200);
    } else if (distance < 10 && distance > 2) { // Attention
      moveBackward(200);
      delay(1000);
      backLeft(150);
      delay(500);
    } else {
      moveForward(150);
    }
  }
}

void following(int speed) {
  float distance = readSensorData();

  int left = digitalRead(leftIR);  // 0: Obstructed   1: Empty
  int right = digitalRead(rightIR);

  if (distance > 5 && distance < 10) {
    moveForward(speed);
  }
  if (!left && right) {
    turnLeft(speed);
  } else if (left && !right) {
    turnRight(speed);
  } else {
    stopMove();
  }
}

void lineTrack(int speed) {
  int lineColor = digitalRead(lineTrackPin); // 0:white  1:black
  Serial.println(lineColor);
  if (lineColor) {
    moveLeft(speed);
  } else {
    moveRight(speed);
  }
}

void irobstacleExample(int speed) {
  int left = digitalRead(leftIR);  // 0: Obstructed   1: Empty
  int right = digitalRead(rightIR);

  if (!left && right) {
    backLeft(speed);
  } else if (left && !right) {
    backRight(speed);
  } else if (!left && !right) {
    moveBackward(speed);
  } else {
    stopMove();
  }
}

void ultrasonicExample(int speed) {
  float distance = readSensorData();
  Serial.println(distance);
  if (distance > 25) {
    moveForward(speed);
  }
  else if (distance < 10 && distance > 2) {
    moveBackward(speed);
  } else {
    stopMove();
  }
}
