//ID 12345
const byte LDRPIN = A0;
const byte LEDPIN = 13;
const byte BUTTONPIN = 2;
int scaryDark = 600;
bool nightLightMode = false;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(LDRPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    if (nightLightMode == true) {
      nightLightMode = false;
    } else {
      nightLightMode = true;
    }
  }
  if (nightLightMode == true) {
    int LDRValue = analogRead(LDRPIN);

    if (LDRValue >= scaryDark) {
      digitalWrite(LEDPIN, HIGH);
      Serial.print("Night light is on, LDR value is ");
      Serial.println(LDRValue);
    } else {
      digitalWrite(LEDPIN, LOW);
      Serial.print("Night light is off, LDR value is ");
      Serial.println(LDRValue);
    }
  }
  delay(250);
}
