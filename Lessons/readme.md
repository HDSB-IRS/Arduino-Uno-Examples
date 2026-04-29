# Tutorial: Adding Libraries and Using the Serial Monitor

When building Arduino projects, you'll often use complex sensors, motors, or screens. Writing the code from scratch to control these components can be incredibly difficult! This is where **Libraries** come in. A library is a collection of pre-written code that someone else has created to make a specific component easy to use.

In this tutorial, we will learn the three ways to install libraries and how to read messages sent from your Arduino using the **Serial Monitor**.

## Objectives
* Understand what a library is and why we use them.
* Learn three different methods to install an Arduino library.
* Open and configure the Serial Monitor to "talk" to your Arduino.

---

## Part 1: Adding Libraries

There are three ways to install a library in the Arduino IDE. We will start with the easiest and most common method.

### Method A: The Library Manager (The Easiest Way)
Use this method for common, officially supported libraries.

1. Open the Arduino IDE.
2. On the left-hand sidebar, click the **Library Manager** icon (it looks like a stack of books). Alternatively, go to **Sketch** > **Include Library** > **Manage Libraries...**
3. A search panel will open on the left. Type the name of the component you are using (e.g., `Servo`, `DHT11`, or `LiquidCrystal`).
4. Scroll through the results to find the specific library you need. 
5. Click the **INSTALL** button next to it. If it asks to install dependencies (other libraries it relies on), click **Install All**.

### Method B: Adding a .ZIP Library (For Third-Party Code)
Sometimes, you will download a library directly from a website like GitHub. It will usually download as a `.zip` file.

1. Do **not** unzip the downloaded file! Leave it as a `.zip`.
2. In the Arduino IDE, go to the top menu and click **Sketch** > **Include Library** > **Add .ZIP Library...**
3. A file browser window will open. Navigate to your `Downloads` folder and select the `.zip` file you just downloaded.
4. Click **Open** (or **Choose** on Mac). 
5. Look at the bottom output console; you should see a message saying "Library added to your libraries."

### Method C: Manual Folder Installation (The Backup Plan)
If the above methods fail, you can install a library manually.

1. Unzip the library file you downloaded. You should now have a normal folder.
2. Rename the folder if necessary (it should not have any weird characters or spaces; e.g., rename `Servo-master` to `Servo`).
3. Move this folder into your Arduino libraries directory:
   * **Windows:** `Documents\Arduino\libraries\`
   * **Mac:** `Documents/Arduino/libraries/`
4. **Restart the Arduino IDE.** The software only checks this folder when it first boots up!

---

## Part 2: Using the Serial Monitor

The **Serial Monitor** is a feature that allows your computer and your Arduino board to send text messages back and forth over the USB cable. It is your best tool for debugging (finding out why your code isn't working) or reading sensor data.

### How to Open It
1. Make sure your Arduino is plugged into your computer via USB.
2. Make sure you have selected the correct Board and Port from the top drop-down menu.
3. Click the **Serial Monitor icon** in the top right corner of the IDE (it looks like a magnifying glass). 
4. A panel will slide up from the bottom of your screen. This is the Serial Monitor.

### Baud Rate
For your Arduino and computer to understand each other, they must be talking at the exact same speed. This speed is called the **Baud Rate**.

1. In your Arduino code, you will usually see a line in the `setup()` function like this: `Serial.begin(9600);` 
2. The number inside the brackets (9600) is the baud rate.
3. Look at the top right corner of the Serial Monitor panel you just opened. You will see a drop-down menu for the baud rate.
4. **Crucial Step:** Make sure the drop-down menu matches the number in your code (e.g., select **9600 baud**). 
   * *If the numbers don't match, you will just see gibberish or backwards question marks printing on the screen!*

You are now ready to install complex sensors and debug your code like a pro!