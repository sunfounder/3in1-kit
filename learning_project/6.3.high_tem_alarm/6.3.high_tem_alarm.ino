#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define buzzerPin 7  //buzzer
#define buttonPin 3  // button
#define potPin A0

/*Thermistor Constat*/
#define temPin  A1  //the thermistor attach to 
#define beta 3950  //the beta of the thermistor
#define resistance 10  //the value of the pull-down resistor

/*Temperature Threshold*/
float upperTem = 0.00;
int state = 0;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  lcd.init();
  lcd.backlight();
  upperTem = EEPROM.read(0);
  delay(1000);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonState, FALLING);
}

void loop()
{
  if (state == 1)
  {
    upperTemSetting();
  }
  else {
    monitoringTemp();
  }
}

void buttonState() {
  state = !state;
}

void upperTemSetting()
{
  int setTem = 0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Adjusting...");
  lcd.setCursor(0, 1);
  lcd.print("Upper Tem: ");

  while (1) {
    lcd.setCursor(11, 1);
    setTem = map(analogRead(potPin), 0, 1023, 0, 100);
    lcd.print(setTem);
    if (state == 0)
    {
      EEPROM.write(0, setTem);
      upperTem = setTem;
      lcd.clear();
      return;
    }
  }
}

void monitoringTemp()
{
  long a = analogRead(temPin);
  float tempC = beta / (log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  float tempF = 1.8 * tempC + 32.0;
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(char(223));
  lcd.print("C   ");
  lcd.setCursor(0, 1);
  lcd.print("Upper: ");
  lcd.print(upperTem);
  lcd.print(char(223));
  lcd.print("C   ");
  delay(300);
  if (tempC >= upperTem)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    delay(10);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }
}
