/*
 * TEJ Tutorial: Pull-Up vs Pull-Down
 * This code turns an LED on with one button logic 
 * and off with another.
 */

const int ledPin = 13;  // Onboard LED
const int btnOn = 2;    // Pull-down button
const int btnOff = 3;   // Pull-up button

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(btnOn, INPUT);
  pinMode(btnOff, INPUT);
}

void loop() {
  // Read the state of the buttons
  int onState = digitalRead(btnOn);
  int offState = digitalRead(btnOff);

  // Button A (Pull-down) is HIGH when pressed
  if (onState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }

  // Button B (Pull-up) is LOW when pressed
  if (offState == LOW) {
    digitalWrite(ledPin, LOW);
  }
}