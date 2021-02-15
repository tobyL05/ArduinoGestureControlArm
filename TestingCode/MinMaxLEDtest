#include <Servo.h>
#include <MPU6050.h>

int valx, valx2,valy,prevValx,prevValx2,prevValy,timereq;
Servo baseServo,frServo,vertServo; 
MPU6050 mpu;
int16_t x,y,z;
const int LEDPin = 13;

void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
Serial.println("Initialize MPU6050");
Serial.print(mpu.testConnection() ? "Connected\n" : "Not Connected\n");
Wire.begin();
mpu.initialize();

pinMode(LEDPin, OUTPUT);

baseServo.attach(12);
frServo.attach(9);
vertServo.attach(10);
TIMSK0 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
mpu.getAcceleration(&x,&y,&z);
valy = map(y, -17000, 17000, 25, 165); //base

Serial.print("base, vert, FR:\t");
  Serial.print(valy); Serial.print("\t");
  Serial.print(valx); Serial.print("\t");
  Serial.println(valx2);


if (valy != prevValy) {
    baseServo.write(valy);
    timereq=abs(valy - prevValy);
    valy = prevValy;
    delay(timereq);
  }
  if(baseServo.read() >= 155 || baseServo.read() <= 35){
    digitalWrite(LEDPin, HIGH);
  }else{
    digitalWrite(LEDPin, LOW);
  }
}
