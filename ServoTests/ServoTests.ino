/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 Modified by Matt Jones
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int moveDist = 1;
int moveDelay = 15;
bool shutterOpen = false;
bool wantOpen = false;

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode(2, INPUT);
}

void loop() {
  myservo.write(180);
  delay(random(1000, 10000));
  myservo.write(170); 
  delay(random(1000, 10000));
  /*for (pos = 0; false; pos += 1) {
    myservo.write(pos);
  }
  */
  /*
  if (digitalRead(2) == HIGH) {
    wantOpen = true;
  } else {
    wantOpen = false;
  }

  if ((shutterOpen == false) && (wantOpen == true)) {
    /*
    for (pos = 0; pos <= 180; pos += moveDist) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      //delay(moveDelay);                       // waits 15ms for the servo to reach the position
      shutterOpen = true;
      //delay(1)
    }
    
    myservo.write(173); 
  } else if ((wantOpen == false) && (shutterOpen == true)) {
    /*
    for (pos = 180; pos >= 0; pos -= moveDist) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      shutterOpen = false;
      //delay(1);                       // waits 15ms for the servo to reach the position
    }
    myservo.write(170);
  } else {
    //do nothing
  }*/
}
