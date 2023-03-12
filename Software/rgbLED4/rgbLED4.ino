//ID 12345
#include <LibPrintf.h>;

const byte BUTTONPIN = 2;
const byte POTPIN = A1;
const byte RLEDPIN = 9;
const byte GLEDPIN = 10;
const byte BLEDPIN = 11;

byte colorChoice = 2; //0=R 1=G 2=B
byte rLedVal = 127;
byte gLedVal = 127;
byte bLedVal = 127;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(POTPIN, INPUT);
  pinMode(RLEDPIN, OUTPUT);
  pinMode(GLEDPIN, OUTPUT);
  pinMode(BLEDPIN, OUTPUT);

  Serial.begin(9600);
}

/*Take the pot value and save to rLedVal or similar

  trimpot val read when button is clicked and saved to variable
  flash the RGB to say where it was saved

  then turn RGB led back on with new values
*/
void loop() {
  int PotVal = analogRead(POTPIN);
  PotVal = map(PotVal, 0, 1023, 0, 255);
  printf("PotVal is %i\n", PotVal);

  if (digitalRead(BUTTONPIN) == HIGH) {
    colorChoice++;
    switch (colorChoice) {
      case 0:
        rLedVal = PotVal;
        flashRGB(RLEDPIN);
        break;
      case 1:
        gLedVal = PotVal;
        flashRGB(GLEDPIN);
        break;
      case 2:
        bLedVal = PotVal;
        flashRGB(BLEDPIN);
        colorChoice = 0; //reset to R once done
        break;
      default:
        Serial.println("ERROR");
        break;
    }
  }
  analogWrite(RLEDPIN, rLedVal);
  analogWrite(GLEDPIN, gLedVal);
  analogWrite(BLEDPIN, bLedVal);
  printf("RGB values are R%i, G%i, B%i\n", rLedVal, gLedVal, bLedVal);
}

//flash the color of the pin given for half second
void flashRGB(byte pin) {
  digitalWrite(RLEDPIN, LOW);
  digitalWrite(GLEDPIN, LOW);
  digitalWrite(BLEDPIN, LOW);

  digitalWrite(pin, HIGH);
  delay(500);

  digitalWrite(RLEDPIN, LOW);
  digitalWrite(GLEDPIN, LOW);
  digitalWrite(BLEDPIN, LOW);
}
