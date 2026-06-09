// Include the IRremote library
#include <IRremote.h>

// The pin the IR receiver's OUT/Signal pin is connected to
const int irReceivePin = 11;

void setup() {
  // Start the serial monitor to view the decoded button presses
  Serial.begin(9600);
  Serial.println("IR Receiver Initialized. Press a button on your remote!");

  // Start the IR receiver and enable the built-in LED to blink when a signal is received
  IrReceiver.begin(irReceivePin, ENABLE_LED_FEEDBACK);
}

void loop() {
  // Check if a complete IR signal has been received and decoded
  if (IrReceiver.decode()) {
    
    // Extract the specific command value of the button that was pressed
    int buttonCommand = IrReceiver.decodedIRData.command;
    
    // Print the command to the Serial Monitor in Hexadecimal format
    Serial.print("Button Command Received: 0x");
    Serial.println(buttonCommand, HEX);

    // Tell the receiver to resume listening for the next button press
    IrReceiver.resume();
  }
}
