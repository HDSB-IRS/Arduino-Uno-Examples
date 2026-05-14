// Define the pins connected to the sensor
const int trigPin = 9;
const int echoPin = 10;

// Variables to hold the duration of the echo and the calculated distance
long duration;
int distance;

void setup() 
{
  // Configure the trigger pin as an output to send the pulse
  pinMode(trigPin, OUTPUT);
  // Configure the echo pin as an input to read the returning pulse
  pinMode(echoPin, INPUT);
  
  // Start serial communication to view results
  Serial.begin(9600);
}

void loop() 
{
  // 1. Clear the trigPin to ensure a clean pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. Send a 10-microsecond HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. Read the echoPin. pulseIn() returns the duration of the pulse in microseconds
  duration = pulseIn(echoPin, HIGH);

  // 4. Calculate the distance (in centimeters)
  // Speed of sound is ~0.034 centimeters per microsecond
  // We divide by 2 because the sound travels out AND back
  distance = duration * 0.034 / 2;

  // 5. Print the result to the Serial Monitor
  Serial.println("Distance: " + String(distance) + " cm");

  // Wait a short moment before taking the next measurement
  delay(100);
}