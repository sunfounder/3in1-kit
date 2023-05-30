#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define buzzerPin 7  //buzzer
#define buttonPin 3  // button
#define potPin A0

/*Thermistor Constat*/
const float referenceResistor = 10000;  // the 'other' resistor
const float beta = 3950;                // Beta value (Typical Value)
const float nominalTemperature = 25;    // Nominal temperature for calculating the temperature coefficient
const float nominalResistance = 10000;  // Resistance value at nominal temperature

const int thermistorPin = A1;  // Pin connected to the thermistor

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
  float adcValue = analogRead(thermistorPin);

  // Convert the reading to resistance
  float voltage = (adcValue / 1023) * 5.0;
  float Rt = referenceResistor * (5.0 - voltage) / voltage;

  // Use the Beta parameter equation to calculate temperature in Kelvin
  float tempK = 1 / (((log(Rt / nominalResistance)) / beta) + (1 / (nominalTemperature + 273.15)));

  // Convert to Celsius
  float tempC = tempK - 273.15;

  // Convert to Fahrenheit
  float tempF = tempC * 1.8 + 32;
  
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
