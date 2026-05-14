// Include the newly installed Adafruit Keypad library
#include "Adafruit_Keypad.h"

// Define the matrix dimensions
const byte ROWS = 4;  // 4 rows
const byte COLS = 3;  // 3 columns

// Define the physical layout of the buttons
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

// Define which Arduino pins are connected to the rows and columns
byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Row 1 to Row 4
byte colPins[COLS] = { 5, 4, 3 };     // Col 1 to Col 3

// Initialize an instance of the keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);

  // Start the keypad
  customKeypad.begin();
  Serial.println("Keypad Initialized. Press any key!");
}

void loop() {
  // Update the keypad state (must be called repeatedly)
  customKeypad.tick();

  // Check if there is a new keypad event (button pressed or released)
  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();

    // Print the character of the key
    Serial.print((char)e.bit.KEY);

    // Check if it was pressed or released and print the action
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.println(" pressed");
    } else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      Serial.println(" released");
    }
  }

  delay(10);  // Small delay for stability
}