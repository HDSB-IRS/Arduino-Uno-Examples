// Include the DHT library
#include "DHT.h"

const int dhtPin = 2;     
const int dhtType = DHT11;   

DHT dht(dhtPin, dhtType);

// Variables for non-blocking delay
unsigned long previousMillis = 0;   // Stores the last time the sensor was updated
const long interval = 2000;         // Interval at which to read sensor (milliseconds)

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Sensor Test - Non-Blocking!");
  dht.begin();
}

void loop() {
  // Capture the current time that the Arduino has been running
  unsigned long currentMillis = millis();

  // Check if 2000 milliseconds have passed since our last reading
  if (currentMillis - previousMillis >= interval) {
    
    // Save the last time you read the sensor
    previousMillis = currentMillis;

    // Read humidity and temperature
    float humidity = dht.readHumidity();
    float tempC = dht.readTemperature();
    float tempF = dht.readTemperature(true);

    // Check if any reads failed
    if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
      Serial.println("Failed to read from DHT sensor!");
    } else {
      // Print the results to the Serial Monitor
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print("%  |  Temperature: ");
      Serial.print(tempC);
      Serial.print("°C / ");
      Serial.print(tempF);
      Serial.println("°F");
    }
  }

  // --> ANY OTHER CODE GOES HERE <--
  // Because we didn't use delay(), the Arduino races through the loop() 
  // thousands of times per second. You could add code here to check a 
  // button state or run a motor, and it would be immediately responsive.
}