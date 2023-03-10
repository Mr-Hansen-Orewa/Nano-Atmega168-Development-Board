//ID 12345
#include <LibPrintf.h>;

const byte BUTTONPIN = 2;
//must be unused pin
const byte RANDOMPIN = A5;

const int DICEMIN = 1;
const int DICEMAX = 6;

void setup() {
  pinMode(BUTTONPIN, INPUT);

  randomSeed(analogRead(RANDOMPIN));
  
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTONPIN) == HIGH) {
    int diceVal = random(DICEMIN, DICEMAX);
    printf("You rolled a dice with %i sides, and got a %i \n", DICEMAX, diceVal);
  }
  delay(250);
}
