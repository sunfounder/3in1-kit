#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the pin numbers
const int ledPin = 8;
const int echoPin = 4;
const int trigPin = 5;
const int buzzerPin = 9;
const long intervalLcd = 1000;
long intervalAlert = -1;

// Create an instance of the LiquidCrystal_I2C class
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD display and backlight
  lcd.init();
  lcd.backlight();
  
  // Set the pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // Read the distance sensor data
  float distanceValue = readSensorData();
  
  // Get the current time in milliseconds
  unsigned long currentMillisL = millis();
  
  // Check if it's time to update the LCD display
  if (currentMillisL - previousMillisL >= intervalLcd) {
    previousMillisL = currentMillisL;
    
    // Print the distance value on the LCD
    lcdPrint(distanceValue);
  }
  
  // Check the distance and trigger the alert if needed
  distanceJudgment(distanceValue);
  
  if (intervalAlert != -1) {
    // Get the current time in milliseconds
    unsigned long currentMillisA = millis();
    
    // Check if it's time to trigger the alert
    if (currentMillisA - previousMillisA >= intervalAlert) {
      previousMillisA = currentMillisA;
      
      // Activate the alert
      alertWork();
    }
  }
}

void alertWork() {
  // Turn on the LED and produce a tone from the buzzer
  digitalWrite(ledPin, HIGH);
  tone(buzzerPin, 440, 100);
  delay(100);
  digitalWrite(ledPin, LOW);
}

void lcdPrint(float distance) {
  // Clear the LCD screen
  lcd.clear();
  
  // Set the cursor position and print the distance value
  lcd.setCursor(0, 0);
  lcd.print("distance:");
  lcd.setCursor(9, 0);
  lcd.print(distance);
}

float readSensorData(void) {
  // Trigger the ultrasonic sensor and calculate the distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00;
  return distance;
}

void distanceJudgment(float distance) {
  // Check the distance and set the alert interval accordingly
  if (distance <= 5) {
    intervalAlert = 300;
  } else if (distance <= 10) {
    intervalAlert = 800;
  } else {
    intervalAlert = -1;
  }
}
