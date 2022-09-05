// set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton1 pin
const int buttonPin2 = 3;     // the number of the pushbutton2 pin
const int rstBtn = 9;     // the number of the rst button pin
const int ledPin1 = 6;        // the number of the LED1 anode(+) pin
const int ledPin2 = 7;       // the number of the LED2 anode(+) pin

int flag = -1;
int timer = 0;

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(rstBtn, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  //enabling serial communication
  Serial.begin(115200);

  // set initial LED state
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);

  Serial.println("GAME START...");
  Serial.println("Click the rst button to play...");
}

void loop()
{
  if (flag == -1 && digitalRead(rstBtn) == LOW) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    Serial.println("Waiting...");
    int randomTime = random(2000, 5000);
    delay(randomTime);

    timer = millis();
    flag = randomTime % 2;
    Serial.println("Light!");
    
    if (flag == 0) {
      digitalWrite(ledPin1, HIGH);
    } else if (flag == 1) {
      digitalWrite(ledPin2, HIGH);
    }
  }
  delay(200);
}


void pressed1() {
  if (flag == -1) {
    return;
  }
  if (flag == 0) {
    int currentTime = millis();
    Serial.print("Correct! You reaction time is : ");
    Serial.print(currentTime - timer);
    Serial.println(" ms");
  } else if (flag == 1) {
    Serial.println("Wrong Click!");
  }
  flag = -1;
}

void pressed2() {
  if (flag == -1) {
    return;
  }
  if (flag == 1) {
    int currentTime =millis();
    Serial.print("Correct! You reaction time is : ");
    Serial.print(currentTime - timer);
    Serial.println(" ms");
  } else if (flag == 0) {
    Serial.println("Wrong Click!");
  }
  flag = -1;
}
