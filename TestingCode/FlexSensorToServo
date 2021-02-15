#include <Servo.h>

const int pinflex = 0;

Servo myServo;

void setup() {
Serial.begin(38400);
myServo.attach(11);

}

void loop() {
int flexpos = analogRead(pinflex);
Serial.println("Analog Read = ");
Serial.println(flexpos);
if(flexpos > 875){
  myServo.write(85);
}else{
  myServo.write(150);
}

delay(25);

}
