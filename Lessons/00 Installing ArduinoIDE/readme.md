# Tutorial: Downloading and Setting Up Arduino IDE

To write code and upload it to an Arduino board, we need to use the **Arduino Integrated Development Environment (IDE)**. The Arduino IDE 2.x is the latest version, featuring an upgraded interface, autocomplete, and a built-in debugger.  The linux version installed in the lab is a bit older, but that's OK.

This tutorial will guide you through installing the Arduino IDE on both Windows and macOS.

## Objectives
* Download the official Arduino IDE 2.x software.
* Install the software correctly on a Windows or Mac computer.
* Understand how to grant necessary permissions for USB drivers.

---

## Step 1: Download the Software (Both Platforms)

Always download the software directly from the official source to ensure you have the safest and most up-to-date version.

1. Open your web browser and navigate to the [Official Arduino Software Page](https://www.arduino.cc/en/software).
2. Look for the **Arduino IDE 2.x** section.
3. Choose the correct download for your operating system:
   * **For Windows:** Click **Windows Win 10 and newer, 64 bits**.
   * **For Mac:** Click **macOS Apple Silicon** (if you have an M1/M2/M3 chip) OR **macOS Intel** (for older Macs).
4. On the donation page, click **"Just Download"**.

---

## Step 2A: Windows Installation

1. **Locate the Installer:** Open your `Downloads` folder and double-click the `arduino-ide_X.X.X_Windows_64bit.exe` file.
2. **Accept the License:** Read through the license agreement and click **I Agree**.
3. **Installation Options:** Choose whether to install the software for "Anyone who uses this computer" or "Only for me," then click **Next**.
4. **Choose Location:** Keep the default installation destination and click **Install**.
5. **⚠️ CRITICAL - Driver Prompts:** During the installation or the first time you open the program, Windows may pop up several security warnings asking if you want to install device software (drivers) from Arduino LLC. **You must click "Install" or "Allow" for all of these.** If you don't, your computer will not be able to talk to your Arduino board!
6. **Finish Setup:** Once the progress bar completes, make sure "Run Arduino IDE" is checked and click **Finish**.

---

## Step 2B: macOS Installation

1. **Locate the Disk Image:** Open your `Downloads` folder and double-click the downloaded `.dmg` file.
2. **Mount and Copy:** A small window will appear. Click and drag the **Arduino IDE** application icon into the **Applications** folder icon right next to it. 
3. **Open the App:** Navigate to your `Applications` folder (or use Spotlight Search by pressing `Cmd + Space`) and open **Arduino IDE**.
4. **Security Prompt:** Because you downloaded this from the internet and not the Mac App Store, macOS will ask if you are sure you want to open it. Click **Open**.
5. **Background Installations:** The first time the IDE opens, it may download some core files and index libraries in the bottom-right corner of the window. Let it finish this process before writing any code.

---

## Step 3: Verify the Installation

To make sure everything is working:

1. Open the Arduino IDE.
2. Look at the interface. You should see a blank "sketch" (the Arduino term for a program) with two main functions pre-written for you: `setup()` and `loop()`.
3. In the top navigation bar, click on **Tools** > **Board** > **Arduino AVR Boards**. You should see a list of classic boards like the Arduino Uno and Arduino Mega. 

**Congratulations!** Your computer is now ready to start programming arduinos.