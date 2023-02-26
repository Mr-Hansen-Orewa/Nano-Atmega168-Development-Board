#include <Servo.h>

const String INTRO = "Testing the soldering on LEDs, Trimpot, LDR, DIP Switches, Button, and the 6 Signal,Power,Ground triples is working";
const unsigned long PAUSEFOR = 1000;
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
const byte SERVOPIN = 0; //use pins x, y, z to test all 6 S,P,G triples



Servo testServo;

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

  testServo.attach(SERVOPIN);

  Serial.begin(9600);
  Serial.println(INTRO);
  Serial.println("Setup done");

  //-------------------------------------
  //test all LEDs turn on and off
  //-------------------------------------
  blinkLED(YLED, 1000);
  blinkLED(RLED, 1000);
  blinkLED(GLED, 1000);
  blinkLED(BLED, 1000);
  Serial.println("LED test done");
}

//NB: each happens in turn so delays to get to a particular
//test will happen and may be noticed
void loop() {

Serial.println(digitalRead(BTN));
  //-------------------------------------
  //test button works
  //-------------------------------------
  if (digitalRead(BTN) == HIGH) {
    Serial.println("in IF");
    digitalWrite(YLED, HIGH);
    //delay(500);
  }else{
    digitalWrite(YLED, LOW);
  }
  Serial.println("Button test done");

  //-------------------------------------
  //test all DIPs and trimpot
  //-------------------------------------
  //brightVal = HIGH;
//  brightVal = analogRead(POT);
//  if (digitalRead(DIP1) == HIGH) {
//    analogWrite(RLED, brightVal);
//  } else {
//    digitalWrite(RLED, LOW);
//  }
//  if (digitalRead(DIP2) == HIGH) {
//    analogWrite(GLED, brightVal);
//  } else {
//    digitalWrite(GLED, LOW);
//  }
//  if (digitalRead(DIP3) == HIGH) {
//    analogWrite(BLED, brightVal);
//  } else {
//    digitalWrite(BLED, LOW);
//  }
//  Serial.println("DIP and trimpot tests done");

  //-------------------------------------
  //test header triples
  //-------------------------------------


  //-------------------------------------
  //test LDR
  //-------------------------------------

}

void blinkLED(byte pin, unsigned long pause) {
  digitalWrite(pin, HIGH);
  delay(pause);
  digitalWrite(pin, LOW);
}
