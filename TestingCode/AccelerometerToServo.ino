#include <MPU6050.h>
#include <Servo.h>
#include <Wire.h>


int valx, valx2, valy, prevValx, prevValx2, prevValy, timereq,pos;
Servo frServo, vertServo, baseServo;
MPU6050 mpu;
int16_t x, y, z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  Serial.println("Initialize MPU6050");
  Serial.print(mpu.testConnection() ? "Connected" : "Not Connected");
  Wire.begin();
  mpu.initialize();
  baseServo.attach(12);
  frServo.attach(9);
  vertServo.attach(10);
  TIMSK0=0; 
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu.getAcceleration(&x, &y, &z);
  valy = map(y, -17000, 17000, 25, 165); //base
  valx = map(x, -17000, 17000, 90, 30); //vert
  valx2 = map (x, -17000, 17000, 50, 120); //fr
  
  Serial.print("base, vert, FR:\t");
  Serial.print(valy); Serial.print("\t");
  Serial.print(valx); Serial.print("\t");
  Serial.println(valx2);

    if (valy != prevValy) {
      delay(timereq);
     baseServo.write(valy);
     timereq=abs(valy - prevValy);
     valy = prevValy;
     delay(timereq);
    }

  if (valx != prevValx) {
    delay(timereq);
    vertServo.write(valx);
    timereq = abs(valx - prevValx);
    valx = prevValx;
    delay(timereq);
  }

  if (valx2 != prevValx2) {
    delay(timereq);
    frServo.write(valx2);
    timereq = abs(valx2 - prevValx2);
    valx2 = prevValx2;
    delay(timereq);
  }
}
