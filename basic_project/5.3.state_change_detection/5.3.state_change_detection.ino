const int  buttonPin = 2;    
const int B_1A = 9;
const int B_1B = 10;

int detectionState = 0;   
int buttonState = 0;         
int lastButtonState = 0;  


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pinMode(B_1A,OUTPUT);
  pinMode(B_1B,OUTPUT);
}

void loop() {
  // Toggle the detectionState each time the button is pressed
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      detectionState=(detectionState+1)%2;
      Serial.print("The detection state is: ");
      Serial.println(detectionState);
    } 
    delay(50);
  }
  lastButtonState = buttonState;
  
  // According to the detectionState, start the motor
  if(detectionState==1){
    digitalWrite(B_1A,HIGH);
    digitalWrite(B_1B,LOW);
  }else{
    digitalWrite(B_1A,LOW);
    digitalWrite(B_1B,LOW);
  }
}
