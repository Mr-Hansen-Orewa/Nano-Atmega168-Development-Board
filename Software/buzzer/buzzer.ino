//ID 12345

const byte BUTTONPIN = 2;
const byte BUZZPIN = 3;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(BUZZPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    //digitalWrite(BUZZPIN, HIGH); // technically works, makes a click but tone is better
    tone(BUZZPIN, 262); //262 is C4 frequency
  } else {
    //digitalWrite(BUZZPIN, LOW); // as above tone is better
    tone(BUZZPIN, 175); //175 is F3 frequency
  }
  delay(250);
}
