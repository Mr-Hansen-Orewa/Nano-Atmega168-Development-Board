//ID 12345

const byte BUTTONPIN = 2;
const byte LEDPIN = 13;
bool ledOff = true;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    if (ledOff == true) {
      ledOff = false;
    } else {
      ledOff = true;
    }
  }
  if (ledOff == false) {
    digitalWrite(LEDPIN, HIGH);
    Serial.println("Light is on");
  } else {
    digitalWrite(LEDPIN, LOW);
    Serial.println("Light is off");
  }
  delay(250);
}
