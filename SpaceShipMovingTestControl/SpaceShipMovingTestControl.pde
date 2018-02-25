import processing.serial.*;
Serial xBeePort;

int send;

void setup() {
  println(Serial.list());
  xBeePort = new Serial(this, "COM6", 9600);
  size(200, 200);
  fill(255, 0, 0);
}

void draw() {
  if (keyPressed) {

      if (key == 't') 
        send = 1;
      else if (key == 'y')
        send = 2;
      else if (key == 'u')
        send = 3;
      else if (key == 'g')
        send = 4;
      else if (key == 'h')
        send = 5;
      else if (key == 'j')
        send = 6;
      else if (key == 'v')
        send = 7;
      else if (key == 'b')
        send = 8;
      else if (key == 'n')
        send = 9;
      
    }

  println(send);
  xBeePort.write(send);
  
}