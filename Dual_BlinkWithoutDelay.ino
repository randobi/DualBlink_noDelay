/*
  Modified Blink without Delay to control timing on 2 leds at different intervals
  A third LED is controlled by a button at random intervals without ineterupting the
  two blinking LEDs and vice-versa. This is done on with a naked ESP8266-12E on a custom board to bread out
  the pins in a single row to make it breadboard friendly.
  Should also work on an Arduino Uno.
  
*/
#include <Arduino.h>
// constants won't change. Used here to set a pin number:
const int ledPin = 2;// the number of the LED pin
const int ledPin_2 = 5;
const int buttonPin = 12; //use to turn on 3rd LED
const int ledPin_3 = 13; //3rd LED

// Variables will change:
int ledState = HIGH;             // ledState used to set the LED
int ledState_2 = LOW;
int buttonState = 0;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store

unsigned long currentMillis = 0; 
unsigned long previous_OnBoardLED_Millis = 0;        // will store last time LED was updated
unsigned long previous_AddedLED_Millis = 0; 

// constants won't change:
unsigned long interval_1;           // interval at which to blink (milliseconds)
unsigned long interval_2;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode (ledPin_3, OUTPUT); //attach to pin 4
  pinMode (buttonPin, INPUT);  // attach a button to light 3rd LED/ pin 12
}

void loop() {
  currentMillis = millis();
  interval_1 = 300;
  interval_2 = 100;
  buttonState = digitalRead(buttonPin);
  
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  
  unsigned long currentMillis = millis();

 if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin_3, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin_3, LOW);
  }

  if (currentMillis - previous_OnBoardLED_Millis >= interval_1) {
    // save the last time you blinked the LED
      previous_OnBoardLED_Millis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
if (currentMillis - previous_AddedLED_Millis >= interval_2) {
    // save the last time you blinked the LED
    previous_AddedLED_Millis = currentMillis;
//Serial.print(currentMillis - previousMillis);
    // if the LED is off turn it on and vice-versa:
    if (ledState_2 == LOW) {
      ledState_2 = HIGH;
    } else {
      ledState_2 = LOW;
    }
    digitalWrite(5, ledState_2);
  }
}
