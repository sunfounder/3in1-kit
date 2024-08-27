#include "pitches.h"

int melody[] = {
  NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, 
  NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_D3, NOTE_D3, 
  NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, 
  NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_C3, 
};

const int buzzerPin=5;

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
char pass[] = "password";

// Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);


int scrubBar=0;
int musicPlayFlag =0;

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin.
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

BLYNK_WRITE(V0)
{
  musicPlayFlag = param.asInt(); // START/PAUSE MUSIC
}

BLYNK_WRITE(V2)
{
  scrubBar=param.asInt();
}

BLYNK_CONNECTED() {
  String songName = "Ode to Joy";
  Blynk.virtualWrite(V3, songName);
}

void myTimerEvent()
{
  if(musicPlayFlag!=0)
  {
    tone(buzzerPin,melody[scrubBar],250);
    scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
    delay(500);
    tone(buzzerPin,melody[scrubBar],250);
    scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
    Serial.println(scrubBar);    
    Blynk.virtualWrite(V2, scrubBar);
    
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
  

}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!

  timer.run(); // Initiates BlynkTimer
}
