//ID 12345

const byte BUTTONPIN = 2;
const byte DIP1PIN = 8;
const byte DIP2PIN = 7;
const byte DIP3PIN = 4;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(DIP1PIN, INPUT);
  pinMode(DIP2PIN, INPUT);
  pinMode(DIP3PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    checkDIP();
  }
  delay(250);
}

void checkDIP() {
  byte decimalVal = 0;
  if (digitalRead(DIP1PIN) == HIGH) {
    decimalVal = decimalVal + 4;
  }
  if (digitalRead(DIP2PIN) == HIGH) {
    decimalVal = decimalVal + 2;
  }
  if (digitalRead(DIP3PIN) == HIGH) {
    decimalVal = decimalVal + 1;
  }
  Serial.print("DIP value in decimal is ");
  Serial.println(decimalVal);

}
