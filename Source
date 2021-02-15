#include <I2Cdev.h>
#include <MPU6050.h>
#include <Servo.h>
#include <Wire.h>

int valx, valx2,valy,prevValx,prevValx2,prevValy,timereq;
Servo baseServo, gripperServo,frServo,vertServo; 
MPU6050 mpu;
int16_t x,y,z;
const int pinflex = 0, buttonPin = 8, LEDPin = 13;

void setup() {
Serial.begin(38400);
Serial.println("Initialize MPU6050");
Serial.print(mpu.testConnection() ? "Connected\n" : "Not Connected\n");
Wire.begin();
mpu.initialize();

// PINS
pinMode(buttonPin, INPUT_PULLUP);
pinMode(LEDPin, OUTPUT);
digitalWrite(LEDPin, LOW);

// Servos
gripperServo.attach(11);
baseServo.attach(12);
frServo.attach(9);
vertServo.attach(10);
TIMSK0 = 0;
}

void loop() { 
// RESET BUTTON //
int buttonState = digitalRead(buttonPin);
if(buttonState == LOW){
  baseServo.write(90);
  frServo.write(90);
  vertServo.write(90);
}else{

// Flex Sensor Code /////////////////////////////
int flexpos = analogRead(pinflex);
Serial.println("Analog Read = ");
Serial.println(flexpos);
if(flexpos > 875){
  gripperServo.write(85); //closed
}else{
  gripperServo.write(150); //opened
}

// MPU6050 Code///////////////////////////////// 
mpu.getAcceleration(&x,&y,&z);
valy = map(y, -17000, 17000, 25, 165); //base
valx = map(x, -17000, 17000, 90, 30); //vert
valx2 = map (x, -17000, 17000, 50, 140); //fr
/*
  Serial.print("base, vert, FR:\t");
  Serial.print(valy); Serial.print("\t");
  Serial.print(valx); Serial.print("\t");
  Serial.println(valx2);
 */

if (valy != prevValy) {
    baseServo.write(valy);
    timereq=abs(valy - prevValy);
    valy = prevValy;
    delay(timereq);
  }

  if (valx != prevValx) {
    vertServo.write(valx);
    timereq=abs(valx - prevValx);
    valx = prevValx;
    delay(timereq);
  }

 if (valx2 != prevValx2) {
    frServo.write(valx2);
    timereq=abs(valx2 - prevValx2);
    valx2 = prevValx2;
    delay(timereq);
 }

}}
