// Include the DHT library
#include "DHT.h"

// The pin the DHT11 data pin is connected to
const int dhtPin = 2;     

// The type of DHT sensor we are using
const int dhtType = DHT11;   

// Initialize the DHT sensor object
DHT dht(dhtPin, dhtType);

void setup() {
  // Start the serial monitor
  Serial.begin(9600);
  Serial.println("DHT11 Sensor Test!");

  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // The DHT11 is a slow sensor. Wait 2 seconds between measurements.
  delay(2000);

  // Read humidity as a percentage
  float humidity = dht.readHumidity();
  
  // Read temperature as Celsius
  float tempC = dht.readTemperature();
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float tempF = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  |  ");
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("°C / ");
  Serial.print(tempF);
  Serial.println("°F");
}