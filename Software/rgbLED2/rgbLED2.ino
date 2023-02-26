//ID 12345

const byte BUTTONPIN = 2;
const byte RLEDPIN = 9;
const byte GLEDPIN = 10;
const byte BLEDPIN = 11;
int counter = 0;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    counter++;
    Serial.print("counter is ");
    Serial.println(counter);
    switch (counter) {
      case 0:
        digitalWrite(RLEDPIN, LOW);
        digitalWrite(GLEDPIN, LOW);
        digitalWrite(BLEDPIN, LOW);
        Serial.println("RGB off");
        break;
      case 1:
        digitalWrite(RLEDPIN, HIGH);
        digitalWrite(GLEDPIN, LOW);
        digitalWrite(BLEDPIN, LOW);
        Serial.println("R on, GB off");
        break;
      case 2:
        digitalWrite(RLEDPIN, LOW);
        digitalWrite(GLEDPIN, HIGH);
        digitalWrite(BLEDPIN, LOW);
        Serial.println("G on, RB off");
        break;
      case 3:
        digitalWrite(RLEDPIN, HIGH);
        digitalWrite(GLEDPIN, HIGH);
        digitalWrite(BLEDPIN, LOW);
        Serial.println("RG on, B off");
        break;
      case 4:
        digitalWrite(RLEDPIN, LOW);
        digitalWrite(GLEDPIN, LOW);
        digitalWrite(BLEDPIN, HIGH);
        Serial.println("B on, RG off");
        break;
      case 5:
        digitalWrite(RLEDPIN, HIGH);
        digitalWrite(GLEDPIN, LOW);
        digitalWrite(BLEDPIN, HIGH);
        Serial.println("RB on, G off");
        break;
      case 6:
        digitalWrite(RLEDPIN, LOW);
        digitalWrite(GLEDPIN, HIGH);
        digitalWrite(BLEDPIN, HIGH);
        Serial.println("GB on, R off");
        break;
      case 7:
        digitalWrite(RLEDPIN, HIGH);
        digitalWrite(GLEDPIN, HIGH);
        digitalWrite(BLEDPIN, HIGH);
        Serial.println("RGB on");
        break;
      default:
        Serial.println("ERROR");
        break;
    }
  }
  delay(250);
}
