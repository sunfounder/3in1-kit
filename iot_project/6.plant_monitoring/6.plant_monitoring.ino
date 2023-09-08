// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "xxxx"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "xxxxxxxx"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "pass";

// Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

#include "DHT.h"

#define DHTPIN 4       // Set the pin connected to the DHT11 data pin
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

#define lightPin A0
#define moisturePin A1
#define pumpA 8

float humidity = 0;
float temperature = 0;

BlynkTimer timer;

BLYNK_WRITE(V0) {
  if (param.asInt() == 1) {
    digitalWrite(pumpA, HIGH);
  } else {
    digitalWrite(pumpA, LOW);
  }
}

int readMoisture() {
  return analogRead(moisturePin);
}

int readLight() {
  return analogRead(lightPin);
}

bool readDHT() {

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return false;
  }
  return true;
}

void myTimerEvent() {
  bool chk = readDHT();
  int light = readLight();
  int moisture = readMoisture();
  if (chk) {
    Blynk.virtualWrite(V4, humidity);
    Blynk.virtualWrite(V5, temperature);
  }
  Blynk.virtualWrite(V6, light);
  Blynk.virtualWrite(V7, moisture);
}

void setup() {
  // Debug console
  Serial.begin(115200);

  dht.begin();

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, myTimerEvent);

  pinMode(pumpA, OUTPUT);
}

void loop() {
  Blynk.run();
  timer.run();  // Initiates BlynkTimer
}
