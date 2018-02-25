const int base1 = A0;
const int base2 = A1;
const int base3 = A2;
const int base4 = A3;
const int base5 = A4;
const int base6 = A5;
const int base7 = A6;
const int base8 = A7;
const int sequence[] = {base1, base2, base3, base4, base5, base6, base7, base8};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for ( int i = 0; i < 8; i++) {
    int reading = analogRead(sequence[i]);
    Serial.print(reading);
    Serial.print(' ');
  }
  Serial.println(' ');
  delay(500);
}


/*
     Serial.print(counter);
  Serial.print(' ');
  // put your main code here, to run repeatedly:
  if (not ended) {
    if (isThere(bases[counter])) {
      counter += 1;
      Serial.println(5);
    }
    else {
      Serial.println(2);
    }
  }
  delay(100);

  if (counter >= 4) {
    Serial.println(10);
    ended = true;
  }
  delay(100);
  }

  bool isThere(int a) {
  int reading = analogRead(a);
  Serial.print(reading);
  Serial.print(' ');
  if (reading >= 200)
    return true;
  else if (reading < 200)
    return false;

  }

*/
