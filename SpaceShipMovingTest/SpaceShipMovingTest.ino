#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3); // RX, TX

Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);
Adafruit_DCMotor *m1 = AFMS.getMotor(1);
Adafruit_DCMotor *m2 = AFMS.getMotor(2);

void setup() {
  // put your setup code here, to run once:
  XBee.begin(9600);
  Serial.begin(9600);
  AFMS.begin();
  m1->setSpeed(80);
  m2->setSpeed(80);

}

void loop() {


  if (XBee.available()) {
    //    Serial.println(XBee.read());
    int dir = XBee.read();


    switch (dir)
    {
      case 1:
        m1->run(RELEASE);
        m2->run(FORWARD);
        break;
      case 2:
        m1->run(FORWARD);
        m2->run(FORWARD);
        break;
      case 3:
        m1->run(FORWARD);
        m2->run(RELEASE);
        break;
      case 4:
        m1->run(BACKWARD);
        m2->run(FORWARD);
        break;
      case 5:
        m1->run(RELEASE);
        m2->run(RELEASE);
        break;
      case 6:
        m1->run(FORWARD);
        m2->run(BACKWARD);
        break;
      case 7:
        m1->run(RELEASE);
        m2->run(BACKWARD);
        break;
      case 8:
        m1->run(BACKWARD);
        m2->run(BACKWARD);
        break;
      case 9:
        m1->run(BACKWARD);
        m2->run(RELEASE);
        break;
      default:
        break;
    }


  }

}
