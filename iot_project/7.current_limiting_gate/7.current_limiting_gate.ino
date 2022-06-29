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


#include <Servo.h>
Servo myservo;//create servo object to control a servo

int angle = 90;

const int irPin = 13; //Pin connected to entrance IR obstale sensor
const int servoPin = 9; //Pin connected to Servo
const int STcp = 12;//Pin connected to ST_CP of 74HC595
const int SHcp = 10;//Pin connected to SH_CP of 74HC595
const int DS = 11; //Pin connected to DS of 74HC595

int datArray[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int count = 0;
int lastState = 0;
int doorFlag = 1;

BlynkTimer timer;

BLYNK_WRITE(V0)
{
  doorFlag = param.asInt(); // Enable Gate
}

void showNumber(int num)
{
  digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
  shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
  digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
}

void operateGate(bool openGate) {
  if (openGate == true) 
  {
    // open gate
    while (angle <= 90) { 
      angle++;
      myservo.write(angle);
      delay(5);
    }
  } else {
    // close gate
    while (angle >= 0){ 
      angle--;
      myservo.write(angle);
      delay(5);
    }
  }
}

void channelEntrance()
{
  int currentState = digitalRead(irPin); // 0:obstacle 1:no-obstacle
  if (currentState == 0 && lastState == 1) {
      count=(count+1)%10;
      Blynk.virtualWrite(V8, count);
      showNumber(count);
      operateGate(true);
  } else if ((currentState == 1 && lastState == 0)) {
    operateGate(false);
  }
  lastState = currentState;
}

void myTimerEvent()
{
  if (doorFlag)
  {
    channelEntrance();
  }
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

  pinMode(STcp, OUTPUT);
  pinMode(SHcp, OUTPUT);
  pinMode(DS, OUTPUT); //74HC595

  //  pinMode(exitPin,INPUT);
  pinMode(irPin, INPUT);

  myservo.attach(servoPin);//attachs the servo on pin 15 to servo object
  myservo.write(0);//back to 0 degrees
  delay(500);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
