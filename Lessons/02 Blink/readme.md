# Tutorial: Blinking the Built-in LED

In this tutorial, we will write our very first Arduino program (called a sketch). We will control the LED that is built directly onto the Arduino board, which means no extra wiring or breadboards are required for this lesson!

## Objectives
* Understand the basic structure of an Arduino sketch.
* Learn how to configure a pin as an output.
* Learn how to turn an electronic component on and off using code.
* Learn how to pause the program for a specific amount of time.

## Materials Needed
* 1x Arduino Board (e.g., Uno, Mega, or Nano)
* 1x USB Cable

## The Built-in LED
Most Arduino boards have a tiny surface-mount LED already soldered onto the board. This LED is internally connected to **Digital Pin 13**. The Arduino software has a special built-in variable called `LED_BUILTIN` that automatically points to this pin, no matter which Arduino board you are using.

## The Code
Open the Arduino IDE. Delete any existing code in the text editor and copy/paste the following code:

```cpp
// This is the setup function. It runs exactly once when the board powers on or resets.
void setup() {
  // Configure the built-in LED pin to act as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

// This is the loop function. It runs over and over again forever.
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED ON (HIGH is the voltage level)
  delay(1000);                      // Wait for 1000 milliseconds (1 second)
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED OFF by making the voltage LOW
  delay(1000);                      // Wait for 1000 milliseconds (1 second)
}
```

## Understanding the Code

An Arduino program is always divided into two main parts:

### 1. void setup()
Everything between the curly braces `{ }` of `setup()` runs only **one time** when the Arduino is turned on. We use this section to set up our pins and initialize sensors.
* **`pinMode(pin, mode)`**: This command tells the Arduino how to treat a specific pin. We are telling it to treat `LED_BUILTIN` as an `OUTPUT` because we want to send power out to the LED. 

### 2. void loop()
Everything between the curly braces `{ }` of `loop()` runs continuously from top to bottom, forever. This is where the main logic of your program lives.
* **`digitalWrite(pin, value)`**: This command changes the voltage on a digital pin. Sending a `HIGH` signal sends 5 Volts (turning the LED on). Sending a `LOW` signal sends 0 Volts (turning the LED off).
* **`delay(ms)`**: Microcontrollers run extremely fast! If we didn't pause the program, the LED would flash on and off millions of times a second, and it would just look continuously dim to human eyes. The `delay()` command pauses the code for a specific number of milliseconds. 1000 milliseconds = 1 second.

## Uploading the Code
1. Connect your Arduino to your computer using the USB cable.
2. In the Arduino IDE, go to **Tools** > **Board** and select your Arduino model (e.g., Arduino Uno).
3. Go to **Tools** > **Port** and select the port your Arduino is connected to (it usually has the Arduino name next to it, or says COM3, /dev/cu.usbserial, etc.).
4. Click the **Upload** button in the top left corner (it looks like a right-pointing arrow).
5. Look at the bottom console for the message **"Done uploading."** Look at your Arduino board. You should now see the built-in LED blinking on and off every second! 

**Challenge:** Try changing the numbers inside the `delay()` functions, upload the code again, and see what happens to the blink rate.