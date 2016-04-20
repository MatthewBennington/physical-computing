/*Copied from "Lab: Using a Transistor to Control High Current Loads with an Arduino
 * by Tom Igoe
 */

const int transistorPin = 9;    // connected to the base of the transistor
 
 void setup() {
   // set  the transistor pin as output:
   pinMode(transistorPin, OUTPUT);
 }
 
 void loop() {
   // read the potentiometer:
   int sensorValue = analogRead(A0);
   // map the sensor value to a range from 0 - 255:
   int outputValue = map(sensorValue, 0, 1023, 0, 255);
   // use that to control the transistor:
   analogWrite(transistorPin, outputValue);
 }
