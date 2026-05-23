// Define the pins for the PIR sensor and the LED
const int pirPin = 2;    
const int ledPin = 13;   

// Variables to keep track of the sensor state
int pirState = LOW;      // Start assuming no motion is detected
int val = 0;             // Variable to read the pin status

void setup() {
  pinMode(ledPin, OUTPUT);  // Initialize LED as an output
  pinMode(pirPin, INPUT);   // Initialize PIR sensor as an input
  
  Serial.begin(9600);       // Start the Serial Monitor

  // PIR sensors need about 10-60 seconds to "warm up" and calibrate 
  // to the infrared signature of the room.
  Serial.println("Calibrating PIR Sensor...");
  delay(15000); // 15 second delay for calibration
  Serial.println("Sensor Active! Waiting for motion...");
}

void loop() {
  val = digitalRead(pirPin);  // Read the state of the PIR sensor

  // If the sensor is triggered (HIGH)
  if (val == HIGH) {            
    digitalWrite(ledPin, HIGH); // Turn the LED ON

    // We only want to print to the serial monitor ONCE when motion starts
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH; // Update the current state
    }
  } 
  // If the sensor is quiet (LOW)
  else {
    digitalWrite(ledPin, LOW); // Turn the LED OFF

    // We only want to print ONCE when motion stops
    if (pirState == HIGH) {
      Serial.println("Motion ended.");
      pirState = LOW; // Update the current state
    }
  }
}