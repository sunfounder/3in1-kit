// Define constants
const float referenceResistor = 10000;  // the 'other' resistor
const float beta = 3950;                // Beta value (Typical Value)
const float nominalTemperature = 25;    // Nominal temperature for calculating the temperature coefficient
const float nominalResistance = 10000;  // Resistance value at nominal temperature

const int thermistorPin = A0;  // Pin connected to the thermistor

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
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

  // Print both temperatures
  Serial.print("Celsius: ");
  Serial.print(tempC);
  Serial.print(" *C | Fahrenheit: ");
  Serial.print(tempF);
  Serial.println(" *F");

  delay(500);
}
