#include <Servo.h>
const int buttonPin = 8;
Servo baseServo,vertServo,frServo;

void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT_PULLUP);
digitalWrite(buttonPin, HIGH);
Serial.begin(38400);
baseServo.attach(12);
frServo.attach(9);
vertServo.attach(10);
TIMSK0 = 0;
} 

void loop() {
  int buttonState = digitalRead(buttonPin);
  // put your main code here, to run repeatedly:
  if(buttonState == LOW){
    baseServo.write(90);
    vertServo.write(90);
    frServo.write(90);
  }else{ 
    baseServo.write(120);
    vertServo.write(60);
    frServo.write(100);
  }
}
