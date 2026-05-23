// Constants for the joystick pins
const int joyXPin = A0;  // Analog pin for X-axis
const int joyYPin = A1;  // Analog pin for Y-axis
const int joyBtnPin = 2; // Digital pin for the button

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  
  // Initialize the button pin as an input with the internal pull-up resistor
  pinMode(joyBtnPin, INPUT_PULLUP);
  
  Serial.println("Basic Joystick Test Started!");
}

void loop() {
  // Read the analog values from the X and Y axes (ranges from 0 to 1023)
  int xValue = analogRead(joyXPin);
  int yValue = analogRead(joyYPin);
  
  // Read the state of the button
  int btnState = digitalRead(joyBtnPin);

  // Print the results to the Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  
  // Since we use INPUT_PULLUP, a pressed button reads LOW (0)
  Serial.print(" | Button: ");
  if (btnState == LOW) {
    Serial.println("PRESSED");
  } else {
    Serial.println("Unpressed");
  }

  // Small delay to make the Serial Monitor readable
  delay(100);
}