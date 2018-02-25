//MAIN Processing sketch that directs the player and interacts with the arduino on the play area

import processing.serial.*;

//The values array that stores a list of the analog inputs from the arduino
int values[] = {0, 0, 0, 0, 0, 0, 0, 0};
int counter = 0;

//Boolean to test whether game has ended or not
boolean ended = false;
String introText = "Dear Astronaut, you will travel from the Sexton Space Station across the Milky Way in a quest to make it the best station of the whole Galaxy. You will need to visit different planets looking for the best scholars of the galaxy, convince them to join the team and bring them back to our space campus, along with other supplies and items.\nTip: Don’t fly too close to black holes or you might burn your stipend-drive system."; 
String text = "";

//Boolean to check if the welcome screen is to be displayed or not
boolean welcome = true;

//An array that stores all the missions (the text) in order
String missions[] = {"First, go to Mars. Find a Martian that wants to study Rocket Engineering. Bonus points if you find water", 
  "Second, go to the Moon. Find a flag for the new campus. That way you can clear up our doubts about who’s been there already…", 
  "Third, go to Mercury and find a Mercurian scholar that wants to expand its Intergalactic Crossroads knowledge", 
  "Fourth, gather food in Saturn to feed the space cats of the dining module. Avoid the flies!", 
  "Fifth, scout Uranus as a possible location to open a new degree-granting Station", 
  "Sixth, go to Earth to pick up the Space Cadets that will take part in the Astro-Candidate Weekend. Make sure to avoid Yale Pluto", 
  "Seventh, travel to Venus to gather data for your hat-stone project. Make sure to avoid Jupiter, it is non visitation", 
  "Congratulations, you have completed the space mission. You are now a universal leader"};

Serial port;
PImage img, endImg, loader;

void setup() {

  size(2560, 1440);

  println(Serial.list());
  port = new Serial(this, "COM9", 9600);
  port.bufferUntil('\n');
  //load two images - one for the general background, the other to show that game has ended 
  img = loadImage("nebulabg.jpg");
  endImg = loadImage("nebulaend.jpg");
  image(img, 0, 0);
}

void draw() {

  //choose which image to load based on whether the game has ended or not 
  loader = ended?endImg:img;
  image(loader, 0, 0);


  print(counter, ' ');
  
  //Check if space ship is at the chosen spot, and if yes, start checking for the next spot. Only do this if the mission has not ended
  if (ended==false) {
    if (isThere(values[counter])==true) {
      counter += 1;
    } 
  }
  if (!ended)
    text = welcome?introText:missions[counter];

//If the space ship is at sensor 7 (black hole), end the game
  if (isThere(values[7])) {
    ended = true;
    text = "You flew too close to the black hole and your ship is ded soz";
  }


  if (counter >= 8) {
    //If the last base has been  crossed, end the mission
    ended = true;
  }

  //Display the text in the center of the screen -
  textAlign(CENTER, CENTER);
  textSize(50);
  fill(255);
  text(text, width*0.25, height*0.25, width*0.5, height*0.5);

  delay(100);
}

//Read the incoming communication from the serial port and store it in aan array called values
void serialEvent(Serial port) {
  // get the ASCII string:
  String inString = port.readStringUntil('\n');
  //print(inString);
  if (inString != null) {
    inString = trim(inString);
    int[] readings = int(split(inString, " "));
    //println("read", readings[0]);
    if (readings.length >= 8) {
      values = readings;
    }
  }
}

void keyPressed() {
  if (keyCode == UP)
    welcome = false;

  if (keyCode == ESC) {
    exit();
  }
}

//A function that takes an integer and returns true if the value is over 200. This is used to detect whether the spaceship is at that certain location
boolean isThere(int a) {
  boolean result = false;
  //print("a", a);
  if (a >= 200) {
    print("yeas");
    result = true;
  } else if (a < 200)
    result = false;
  return result;
}