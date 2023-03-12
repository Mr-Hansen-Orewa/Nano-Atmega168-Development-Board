//ID 12345
//#include <LibPrintf.h>;

const byte POTPIN = A1;
const byte RLEDPIN = 9;
const byte GLEDPIN = 10;
const byte BLEDPIN = 11;

void setup() {
  pinMode(POTPIN, INPUT);
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int PotVal = analogRead(POTPIN);
  PotVal = map(PotVal, 0, 1023, 0, 255);
  Serial.print("PotVal is ");
  Serial.println(PotVal);
  //OR
  //printf("PotVal is %i\n", PotVal);

  analogWrite(RLEDPIN, PotVal);
  analogWrite(GLEDPIN, PotVal);
  analogWrite(BLEDPIN, PotVal);
}
