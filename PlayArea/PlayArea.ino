/*
   This sketch reads the sensors of the play area.
   It then prints the readings which are read by a procesing sketch that controls the storyline
*/

//Declaration of sensors in the order that the storyline needs them to be.
const int base1 = A4;
const int base2 = A0;
const int base3 = A6;
const int base4 = A2;
const int base5 = A7;
const int base6 = A1;
const int base7 = A5;
const int base8 = A3;

//Create an array, or a list of those bases
const int bases[] = {base1, base2, base3, base4, base5, base6, base7, base8};

//Initialize a counter variable to loop over them
int counter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  //Loop over the bases array and print the readings to the Serial port which will then be picked up by the processing sketch
  for ( int i = 0; i < 8; i++) {
    int reading = analogRead(bases[i]);
    Serial.print(reading);
    Serial.print(' ');
  }
  Serial.println(' ');
  delay(50);

}
