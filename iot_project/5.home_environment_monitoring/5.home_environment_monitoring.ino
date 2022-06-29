// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "xxxxxx"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxx"

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

#include <dht.h>
dht DHT;
#define DHT11_PIN 4
const int lightPin=A0;

double roomHumidity = 0;
double roomTemperature = 0;

BlynkTimer timer;

int readLight(){
  return analogRead(lightPin);
}

bool readDHT() {
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:
      Serial.print("OK,\t");
      roomHumidity = DHT.humidity;
      Serial.print(roomHumidity, 1);
      Serial.print(",\t");
      roomTemperature = DHT.temperature;
      Serial.println(roomTemperature, 1);
      //    delay(1000);
      return true;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Time out error,\t");
      //    delay(20);
      break;
    default:
      Serial.println("Unknown error,\t");
      break;
  }
  return false;
}

void myTimerEvent()
{
  bool chk = readDHT();
  int light = readLight();
  if(chk==true){
    Blynk.virtualWrite(V4,roomHumidity);
    Blynk.virtualWrite(V5,roomTemperature);
  }
  Blynk.virtualWrite(V6,light);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
