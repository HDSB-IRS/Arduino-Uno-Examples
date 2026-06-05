# Tutorial: Using an IR Receiver and Remote Control

In this lesson, you will learn how to connect an IR (Infrared) receiver module to your Arduino and decode signals from a standard infrared remote control.

## Objectives
* Understand the basics of infrared communication.
* Learn how to install and use the `IRremote` library.
* Decode signals from an IR remote and display the button commands on the Serial Monitor.

## Materials Needed
* 1x Arduino Board
* 1x USB Cable
* Jumper Wires
* 1x Breadboard
* 1x IR Receiver Module (e.g., VS1838B or HX1838)
* 1x IR Remote Control

## Component Review

Infrared (IR) light is outside the visible spectrum of the human eye, but it is highly effective for short-range wireless communication. When you press a button on an IR remote, a small infrared LED on the front flashes very rapidly in a specific pattern. 

An **IR Receiver Module** is designed to "see" these invisible flashes. It detects the specific frequency of the flashes (usually 38 kHz to avoid interference from sunlight and regular lightbulbs), demodulates the signal, and sends a clean digital pulse to the Arduino. 

Because every button on the remote sends a slightly different flashing pattern, the Arduino can decode these patterns into specific hex values (like `0x45` or `0x16`), allowing you to trigger different actions in your code depending on which button was pressed.

## Circuit Diagrams

Here are the visual references for building this circuit. Use the wiring diagram to see the physical layout on the breadboard, and use the schematic to understand the electrical flow.

### Schematic Diagram
![Schematic Diagram](schematic.png)

### Wiring Diagram
![Wiring Diagram](wiring.png)

## Hardware Setup
IR Receiver modules typically have 3 pins, though the order can vary depending on the manufacturer. Always check the labels on your specific module. They are generally labeled: **GND** (or -), **VCC** (or +), and **OUT** (or S/Y).

1. **Power:** Connect the **VCC** pin of the IR receiver to the **5V** pin on the Arduino.
2. **Ground:** Connect the **GND** pin of the IR receiver to any **GND** pin on the Arduino.
3. **Signal:** Connect the **OUT** (or Signal) pin to **Digital Pin 11** on the Arduino.

## Library Installation
Decoding the complex timing of IR signals manually is very difficult. We will use a highly popular library to handle this for us.
1. Open the Arduino IDE.
2. Go to **Sketch** > **Include Library** > **Manage Libraries...**
3. In the search bar, type `IRremote`.
4. Find the library titled **IRremote** by shirriff (z3t0, Armin Joachimsmeyer) and click **Install**. 

## The Code
Open the Arduino IDE, delete any existing code, and copy the following into the editor. *(Note: This uses the modern IRremote v3.0+ syntax).*

```cpp
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
```

## Understanding the Code

* **`#include <IRremote.h>`**: This imports the library we installed, which takes care of reading the high-speed pulses from the receiver module.
* **`const int irReceivePin = 11;`**: We define a constant integer to tell the Arduino which pin the sensor's data line is connected to.
* **`IrReceiver.begin(irReceivePin, ENABLE_LED_FEEDBACK);`**: Placed in the `setup()` function, this starts the receiver. The `ENABLE_LED_FEEDBACK` argument is a helpful feature of the library that automatically blinks the Arduino's onboard LED (Pin 13) every time it sees an IR signal, letting you know your remote is working!
* **`IrReceiver.decode()`**: This function checks if a new, complete IR code has been fully read. It returns `true` if a button was pressed, which allows us to step into the `if` statement.
* **`IrReceiver.decodedIRData.command`**: When a signal is successfully decoded, the library stores the information in a data structure. We access the `.command` property to get the specific number assigned to the button that was pressed.
* **`Serial.println(buttonCommand, HEX);`**: We print the button code to the Serial Monitor. Adding `, HEX` formats the number in hexadecimal (Base-16), which is the standard way IR codes are read and shared.
* **`IrReceiver.resume();`**: This is a critical step! Once the library decodes a signal, it pauses so it doesn't accidentally overwrite the data before you can use it. You must call `resume()` to reset the receiver so it can listen for the next button press.