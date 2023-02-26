//ID 12345

const byte BUTTONPIN = 2;
const byte LEDPIN = 13;

void setup() {
  pinMode(BUTTONPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(digitalRead(BUTTONPIN) == HIGH){
    digitalWrite(LEDPIN, HIGH);
  }else{
        digitalWrite(LEDPIN, LOW);
  }
  delay(250);
}
