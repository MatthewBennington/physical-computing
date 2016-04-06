/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 Modified by Matt Jones March 2016
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
  delay(random(5000, 10000));
  myservo.write(170); 
  delay(random(5000, 10000));
  
}
