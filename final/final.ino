#include <Servo.h>

Servo frontServo;
int pos = 180;
unsigned long echo = 0;
int ultraSoundSignal = 2; // Ultrasound signal pin
unsigned long ultrasoundValue = 0;
bool forward = true; //Stores if the puppies are facing the viewer
int i = 0; //Determins if people are facing
int front = 165;
int back = 14;

void setup() {
  Serial.begin(9600);
  pinMode(ultraSoundSignal, OUTPUT);
  pinMode(11, OUTPUT); //Added by Matt for LED
  frontServo.attach(3);  // attaches the servo on pin 3 to the servo object
  frontServo.write(front); // 165 seems to be as good as we can get, 14 seems to be a decent opposite
  delay(1000);
  frontServo.detach();
  delay(50);
  //frontServo.write(90);
}

unsigned long ping()
{
  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignal, LOW); // Send low pulse
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW); // Holdoff
  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignal, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echo = pulseIn(ultraSoundSignal, HIGH); //Listen for echo
  ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValue;
}

void loop()
{
  int x = 0;
  x = ping();
  frontServo.detach();
  Serial.println(x); //Print distance

  Serial.println(i); //Print arbitrary value for proximity

  //Serial.println(frontServo.read());
  Serial.println("^^^");
  if (forward == true) {
    Serial.println("forward");
  } else {
    Serial.println("Backwards");
  }

  i += (144 - x);
  if (i > 0) {
    i -= 10;
  } else {
    i = 0;
  }
  if (i > 800) {
    //turnAway()
    if (forward) {
      frontServo.attach(3);
      digitalWrite(11, HIGH);
      Serial.println("facing away");
      for (pos = front; pos >= back; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        frontServo.write(pos);              // tell servo to go to position in variable 'pos'
        //Serial.println(pos);
        //The other two as well
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      frontServo.detach();
      i = 240;
      forward = false;
    }
    delay(5000);
  }
  else if ((i < 200) && (forward == false)) {
    //turnToFaceOut()
    frontServo.attach(3);
    digitalWrite(11, LOW);
    for (pos = back; pos <= front; pos += 1) { // goes from 180 degrees to 0 degrees
      frontServo.write(pos);              // tell servo to go to position in variable 'pos'
      //The other two as well
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    Serial.println("Facing towards");
    forward = true;
    frontServo.detach();
  }
  delay(250); //delay 1/4 seconds.
}
