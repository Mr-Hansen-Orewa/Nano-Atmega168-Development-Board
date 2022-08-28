#include <Servo.h>

//const String INTRO = "Testing the soldering on LEDs, Trimpot, LDR, DIP Switches, Button, and the 6 Signal,Power,Ground triples is working";
//const unsigned long PAUSEFOR = 1000;
//Define all the pins
const byte YLED = 13;
const byte RLED = 9; //PWM
const byte GLED = 10; //PWM
const byte BLED = 11; //PWM
const byte LDR = A0;
const byte POT = A1;
const byte BTN = 2;
const byte DIP1 = 4;
const byte DIP2 = 7;
const byte DIP3 = 8;
const byte SERVO1PIN = 6;
const byte SERVO2PIN = 5;
const byte SERVO3PIN = 3;

Servo testServo1;
Servo testServo2;
Servo testServo3;

void setup() {
  pinMode(LDR, INPUT);
  pinMode(POT, INPUT);
  pinMode(BTN, INPUT);
  pinMode(DIP1, INPUT);
  pinMode(DIP2, INPUT);
  pinMode(DIP3, INPUT);

  pinMode(YLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);

  testServo1.attach(SERVO1PIN);
  testServo1.write(0);
  testServo2.attach(SERVO2PIN);
  testServo2.write(0);
  testServo3.attach(SERVO3PIN);
  testServo3.write(0);

  Serial.begin(9600);
  // Serial.println(INTRO);
  Serial.println("Setup done");

  //-------------------------------------
  //test all LEDs turn on and off
  //-------------------------------------
  blinkLED(byte YLED, 1000);
  blinkLED(byte RLED, 1000);
  blinkLED(byte GLED, 1000);
  blinkLED(byte BLED, 1000);
  Serial.println("LED test done");
}

//NB: each happens in turn so delays to get to a particular
//test will happen and may be noticed
void loop() {

  //-------------------------------------
  //test button works
  //-------------------------------------
  if (digitalRead(BTN) == HIGH) {
    digitalWrite(YLED, !digitalRead(YLED));
    delay(500); //to stop rapid changing if your click is slow
  }
  Serial.println("Button test done");

  //-------------------------------------
  //test all DIPs and trimpot
  //-------------------------------------
  //brightVal = HIGH;
  brightVal = analogRead(POT);
  if (digitalRead(DIP1) == HIGH) {
    analogWrite(RLED, brightVal);
  } else {
    digitalWrite(RLED, LOW);
  }
  if (digitalRead(DIP2) == HIGH) {
    analogWrite(GLED, brightVal);
  } else {
    digitalWrite(GLED, LOW);
  }
  if (digitalRead(DIP3) == HIGH) {
    analogWrite(BLED, brightVal);
  } else {
    digitalWrite(BLED, LOW);
  }
  Serial.println("DIP and trimpot tests done");

  //-------------------------------------
  //test LDR and header triples
  //-------------------------------------
  int servoPos = analogRead(LDR);
  servoPos = map(servoPos, 0, 1023, 0, 180);

  testServo1.write(servoPos);
  testServo2.write(servoPos);
  testServo3.write(servoPos);
  delay(500);
  //reset to 0 position
  testServo1.write(0);
  testServo2.write(0);
  testServo3.write(0);
}

void blinkLED(byte pin, unsigned long wait) {
  digitalWrite(pin, HIGH);
  delay(wait);
  digitalWrite(pin, LOW);
}
