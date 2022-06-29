const int soilMoisture = A0;
const int redPin = 11;  // R petal onmodule connected to digital pin 11 
const int greenPin = 10;  // G petal onmodule connected to digital pin 10 
const int bluePin = 9;  // B petal onmodule connected to digital pin 9 

int threshold = 900;

void setup() {
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int sensorValue = analogRead(soilMoisture);
  Serial.println(sensorValue);
  if(sensorValue>threshold){
    color(255,0,252); // red
  }else{
    color(0,112,255); // blue
  }
}

void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
