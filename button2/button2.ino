/*
  Button2

  When button (attached to pin 2) is pushed, the LED (connected to digital 
  pin 13) will blink at an interval of 100 milliseconds. LED will turn off 
  when button is not pushed.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  This project was created in reference to... 
    created 2005
    by DojoDave <http://www.0j0.org>
    modified 30 Aug 2011
    by Tom Igoe
    http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const long interval = 100;   //interval at which the LED blinks

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int ledState = HIGH;         //LED started turned on

//vafriable holds time therefore "unsigned long"
unsigned long prevMillis = 0;  //store last time updated in milliseconds

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value: HIGH or LOW
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. 
 
  if (buttonState == HIGH) {      //button is pushed. buttonState is HIGH:
    //stores current milliseconds
    unsigned long currMillis = millis();
    //if time since milliseconds were last checked is larger or equal to the 
    //interval, change the state of the LED
    if (currMillis - prevMillis >= interval) {
      prevMillis = currMillis;
      if(ledState == LOW){
        ledState = HIGH;
      }else {
        ledState = LOW;
      }
     //write the state
     digitalWrite(ledPin, ledState); 
    }
  } else{      //button is not pushed. buttonState is LOW:
      digitalWrite(ledPin, LOW);   //LED is off
    }
}
