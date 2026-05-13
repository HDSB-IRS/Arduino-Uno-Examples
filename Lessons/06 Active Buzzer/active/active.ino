const int buzzerPin = 8;

void setup() {
  // Configure the buzzer pin to behave as an OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Turn the buzzer ON by sending 5 Volts (HIGH)
  digitalWrite(buzzerPin, HIGH);
  delay(1000);  // Wait for 1000 milliseconds (1 second)

  // Turn the buzzer OFF by sending 0 Volts (LOW)
  digitalWrite(buzzerPin, LOW);
  delay(1000);  // Wait for 1 second before repeating the loop
}