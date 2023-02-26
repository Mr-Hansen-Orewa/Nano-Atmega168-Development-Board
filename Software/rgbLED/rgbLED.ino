//ID 12345

const byte BUTTONPIN = 2;
const byte RLEDPIN = 9;
const byte GLEDPIN = 10;
const byte BLEDPIN = 11;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    digitalWrite(RLEDPIN, HIGH);
    digitalWrite(GLEDPIN, HIGH);
    digitalWrite(BLEDPIN, HIGH);
    Serial.println("RGB on");
  } else {
    digitalWrite(RLEDPIN, LOW);
    digitalWrite(GLEDPIN, LOW);
    digitalWrite(BLEDPIN, LOW);
    Serial.println("RGB off");
  }
  delay(250);
}
