const int ledPin = 13;  // The pin the onboard LED is attached to
const int tiltPin = 2;  // The pin the tilt sensor is attached to

void setup() {
  pinMode(ledPin, OUTPUT);  // Initialize the ledPin as an output

  // Initialize the tilt pin as an input and turn on the internal pull-up resistor
  pinMode(tiltPin, INPUT_PULLUP);

  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the state of the tilt sensor
  int digitalVal = digitalRead(tiltPin);
  Serial.println("Read Value: " + String(digitalVal));


  // If the switch is open (un-tilted), the pull-up resistor makes it HIGH
  if (digitalVal == HIGH) {
    digitalWrite(ledPin, LOW);  // Turn the LED off
    Serial.println("State: HIGH (Switch Open / Upright)");
  }
  // If the switch is closed (tilted), the connection to GND makes it LOW
  else {
    digitalWrite(ledPin, HIGH);  // Turn the LED on
    Serial.println("State: LOW (Switch Closed / Tilted)");
  }

  // A short delay so the Serial Monitor output is readable
  delay(250);
}