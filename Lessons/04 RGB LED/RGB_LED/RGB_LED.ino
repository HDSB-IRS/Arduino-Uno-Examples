// Define Pin Constants
const blueLED 3;
const greenLED 5;
const redLED 6;

// Define variables
int redValue;
int greenValue;
int blueValue;

int delayTime = 10;  // fading time between colors

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
}

void loop() {
  redValue = 255;  // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1)  // fades out redLED bring greenLED full when i=255
  {
    redValue -= 1;
    greenValue += 1;
    analogWrite(redLED, redValue);
    analogWrite(greenLED, greenValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1)  // fades out greenLED bring blueLED full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(greenLED, greenValue);
    analogWrite(blueLED, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for (int i = 0; i < 255; i += 1)  // fades out blueLED bring redLED full when i=255
  {
    blueValue -= 1;
    redValue += 1;
    analogWrite(blueLED, blueValue);
    analogWrite(redLED, redValue);
    delay(delayTime);
  }
}