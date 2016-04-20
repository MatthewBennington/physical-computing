import processing.serial.*;

  float xPos = 0; // horizontal position of the graph
  float yPos = 0; // vertical position of the graph

void setup () {
  Serial myPort;
  size(800, 600);        // window size
  // change the number below to match your port:
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
  background(#081640);

  
}

void serialEvent (Serial myPort) {
  // get the byte:
  int inByte = myPort.read();
  // print it:
  println(inByte);
  yPos = height - inByte;
}

void draw () {
   // draw the line in a pretty color:
  stroke(#A8D9A7);
  line(xPos, height, xPos, yPos);
  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    // clear the screen by resetting the background:
    background(#081640);
  } else {
    // increment the horizontal position for the next reading:
    xPos++;
  }
}