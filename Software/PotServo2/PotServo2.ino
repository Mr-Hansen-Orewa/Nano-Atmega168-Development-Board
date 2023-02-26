//ID 12345
#include <Servo.h>

Servo wiper;
const byte BUTTONPIN = 2;
const byte POTPIN = A1;
const byte SERVOPIN = 5;
const int COMBINATION = 200;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(POTPIN, INPUT);
  wiper.attach(SERVOPIN);
  wiper.write(0);
  
  Serial.begin(9600);
}

void loop() {
  int PotVal = analogRead(POTPIN);
  Serial.print("PotVal is");
  Serial.println(PotVal);
  if(digitalRead(BUTTONPIN) == HIGH && PotVal == COMBINATION){
    wiper.write(180);
    delay(1000);
  }
}
