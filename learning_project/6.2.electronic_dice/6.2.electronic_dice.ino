const int STcp = 12;//Pin connected to ST_CP of 74HC595
const int SHcp = 8;//Pin connected to SH_CP of 74HC595
const int DS = 11; //Pin connected to DS of 74HC595
const int buttonPin = 2;
int datArray[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f,  0x6f};
int number = 0;
int state = 0;

void setup ()
{
  //set pins to output
  pinMode(STcp, OUTPUT);
  pinMode(SHcp, OUTPUT);
  pinMode(DS, OUTPUT);
  pinMode(buttonPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
}

void loop()
{
  if (state == 0) {
    showNumber((int)random(1, 7));
    delay(50);
  }
}

void showNumber(int num) {
  digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
  shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
}


void rollDice() {
  state = !state;
}
