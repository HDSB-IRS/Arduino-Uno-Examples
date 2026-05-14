// Include the built-in Servo library
#include <Servo.h>

// Create a servo object to control our SG90
Servo myServo;

const int servoPin = 9;  // The digital pin the servo signal wire is connected to
int angle = 0;           // Variable to store the current servo position

void setup() {
  // Attach the servo object to the specified pin
  myServo.attach(servoPin);
}

void loop() {
  // Sweep from 0 degrees to 180 degrees
  for (angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);  // Tell servo to go to the position in variable 'angle'
    delay(15);             // Wait 15ms for the servo to reach the position
  }

  // Sweep from 180 degrees back to 0 degrees
  for (angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);
    delay(15);
  }
}