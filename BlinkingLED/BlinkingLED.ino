// Example 01 : Blinking LED
const int LED = 13; // LED connected to
                    // digital pin 13
void setup()
{
  pinMode(LED, OUTPUT);
}
void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
// sets the digital
// pin as output
  // turns the LED on
  // waits for a second
  // turns the LED off
  // waits for a second
}

