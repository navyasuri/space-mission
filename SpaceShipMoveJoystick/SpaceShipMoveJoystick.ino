//Include all necessary libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <SoftwareSerial.h>

//Declare a new Serial port for the XBee shield
SoftwareSerial XBee(2, 3); // RX, TX

//Initialize a new instance of the MotorShield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

//Initialize two motors - m1 is the left wheel and m2 is the right wheel
Adafruit_DCMotor *m1 = AFMS.getMotor(1);
Adafruit_DCMotor *m2 = AFMS.getMotor(2);

void setup() {
  XBee.begin(9600);
  Serial.begin(9600);
  AFMS.begin();

  //Let the motors run at a speed of 65 - this value was chosen after playing around with different speeds
  m1->setSpeed(65);
  m2->setSpeed(65);
}

void loop() {

  if (XBee.available()) {

    //Read the incoming value from the XBee (an integer value that corresponds to a direction that the motor must travel in
    int dir = XBee.read();

    /*
       Key for the Direction - this is a copy of the key from the where function in the controller sketch
        0 - stop
        1 - forward
        2 - left
        3 - right
        4 - back
    */

    //Run a switch case construct over the direction integer and move the motors accordingly    
    switch (dir)
    {
      case 0:
        m1->run(RELEASE);
        m2->run(RELEASE);
        break;
      case 1:
        m1->run(FORWARD);
        m2->run(FORWARD);
        break;
      case 2:
        m1->run(BACKWARD);
        m2->run(FORWARD);
        break;
      case 3:
        m1->run(FORWARD);
        m2->run(BACKWARD);
        break;
      case 4:
        m1->run(BACKWARD);
        m2->run(BACKWARD);
        break;
      default:
        m1->run(RELEASE);
        m2->run(RELEASE);
        break;
    }


  }

}
