/*
  Uno analogWrite() test

  This sketch fades LEDs up and down together on digital pins 9-11

  The circuit:
  - LEDs attached from pins 9 through 11 to ground.

  created with reference to arduino example ...
    created 8 Feb 2009
    by Tom Igoe
    This example code is in the public domain.
     http://www.arduino.cc/en/Tutorial/AnalogWriteMega
*/

// These constants won't change. They're used to give names to the pins used:
const int lowestPin = 9;
const int highestPin = 11;


void setup() {
  // set pins 9 through 11 as outputs:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  //brighten LEDs at the same rate
  for (int brightness = 0; brightness < 255; brightness++){
      analogWrite(9, brightness);
      analogWrite(10, brightness);
      analogWrite(11, brightness);
      delay(2);
    }
  //fade LEDs at the same rate
  for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(9, brightness);
      analogWrite(10, brightness);
      analogWrite(11, brightness);
      delay(2);
    }
  //pause between fades
  delay(100);
}
