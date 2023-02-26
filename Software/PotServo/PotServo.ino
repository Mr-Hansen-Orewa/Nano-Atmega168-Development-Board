//ID 12345
#include <Servo.h>

Servo wiper;
const byte POTPIN = A1;
const byte SERVOPIN = 5;

void setup() {
  pinMode(POTPIN, INPUT);
  wiper.attach(SERVOPIN);

  Serial.begin(9600);
}

void loop() {
  int PotVal = analogRead(POTPIN);
  Serial.print("PotVal before map function is used ");
  Serial.println(PotVal);
  PotVal = map(PotVal, 0, 1023, 0, 180);
  Serial.print("PotVal after map function is used ");
  Serial.println(PotVal);
  wiper.write(PotVal);
  delay(15);
}
