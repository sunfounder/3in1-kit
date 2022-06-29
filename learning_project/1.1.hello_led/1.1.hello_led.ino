//the number of the LED pin
const int ledPin = 9;

void setup()
{
  //initialize the digital pin as an output
  pinMode(ledPin,OUTPUT);
}

//the loop routine runs over and over again forever
void loop()
{
  digitalWrite(ledPin,HIGH);//turn the LED on 
  delay(500);               //wait for half a second
  digitalWrite(ledPin,LOW); //turn the LED off
  delay(500);               //wait for half a second
}
/*************************************************/
