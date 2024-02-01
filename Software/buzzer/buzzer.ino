//ID 12345

const byte BUTTONPIN = 2;
const byte BUZZPIN = 3;

boolean latch = false;

const byte NOTE_A1  55;
const byte NOTE_AS1 58;
const byte NOTE_B1  62;
const byte NOTE_C2  65;
const byte NOTE_CS2 69;
const byte NOTE_D2  73;
const byte NOTE_DS2 78;
const byte NOTE_E2  82;
const byte NOTE_F2  87;
const byte NOTE_FS2 93;
const byte NOTE_G2  98;
const byte NOTE_GS2 104;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(BUZZPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    latch = HIGH;
    delay(250); //to debounce
  } else {
    latch = LOW;
    delay(250); //to debounce
  }

  if (latch == HIGH) {
    tone(BUZZPIN, 262);  //262 is C4 frequency
  } else {
    notone();  //turn off tones
  }
}
