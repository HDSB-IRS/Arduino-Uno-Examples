// Define the pin connected to the passive buzzer
const int buzzerPin = 8;

void setup() {
  // The tone() function automatically sets the pin as an output, 
  // so we actually don't strictly need anything here, but it's 
  // good practice to leave it with an empty setup for this simple sketch.
}

void loop() {
  // Play Middle C (262 Hz) for 300 milliseconds
  tone(buzzerPin, 262); 
  delay(300);
  
  // A short pause between notes so they don't blend together
  noTone(buzzerPin);
  delay(50);

  // Play D (294 Hz) for 300 milliseconds
  tone(buzzerPin, 294);
  delay(300);
  
  noTone(buzzerPin);
  delay(50);

  // Play E (330 Hz) for 300 milliseconds
  tone(buzzerPin, 330);
  delay(300);

  // Stop the tone and wait 2 seconds before playing the sequence again
  noTone(buzzerPin);
  delay(2000); 
}