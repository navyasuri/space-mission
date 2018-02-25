#include <SoftwareSerial.h>
//Declare a new Serial port for the XBee shield
SoftwareSerial XBee(2, 3);

//Variables Declaration
const int xPin = A1;
const int yPin = A0;
int xPos = 512;
int yPos = 512;
int toGo = 0;

void setup() {
  XBee.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //Read the x and y positions of the joystick from the analog pins
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  
  /*
   * Key for the where function
      0 - stop
      1 - forward
      2 - left
      3 - right
      4 - back
  */

  //the where functions returns a unique integer for each direction, which is keyed in the comment above
  toGo = where(xPos, yPos);

  //the unique direction obtained from the where() function is passed on from the xbee to the spaceship where it is read and the spaceship moves accordingly
  XBee.write(toGo);
  delay(50);  
  
}

int where(int xPos, int yPos) {

  if ((xPos > 500 && xPos < 524) && (yPos > 500 && yPos < 524)) {
    return 0;
  }

  else if ( (xPos > 500 && xPos < 524) && (yPos > 524) ) {
    return 1;
  }

  else if ( (xPos < 500) && (yPos > 500 && yPos < 524) ) {
    return 2;
  }

  else if ( (xPos > 524) && (yPos > 500 && yPos < 524) ) {
    return 3;
  }

  else if ( (xPos > 500 && xPos < 524) && (yPos < 500) ) {
    return 4;
  }

  else {
    return 0;
  }
}

