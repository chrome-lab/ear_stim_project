# Ear Stim Project

 This repository contains the code to generate a 2Hz excitation of a vibration motor for the ear stim project.

 The code was generated to be used with the Sparkfun nRF52840 Pro Mini Breakout board, so all instructions will be geared towards the use of that specific hardware. However, the code may work with other Arduino/C++ based boards.

 ### Most Recent Version

[v1.0.0](https://github.com/mfdunlap/ear_stim_project/releases/tag/v1.0.0)

### Previous Versions

</br>

## Installation (HI THIS IS A CHANGE)

### Preparing the Environment

1) Install the [Arduino IDE](https://www.arduino.cc/en/software) (must be v1.6.12 or later).

2) Download the most recent version of the [Ear Stim Project repo](https://github.com/mfdunlap/ear_stim_project/releases/tag/v1.0.0).

3) Open the Arduino IDE.

4) Navigate to **Preferences**.

5) Add the following link to the *Additional Board Manager URL* box.  
[https://adafruit.github.io/arduino-board-index/package_adafruit_index.json](https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
)

6) Go to **Tools** > **Board** > **Board Manager**.

7) Search for "*nRF*" and look for the ***Adafruit nRF52*** package.

8) Select the most recent version of the package and click *Install*.

### Modifying the nRF52 Board Library

1) In your file exporer, navigate to the location where the Ear Stim Repo is saved on your computer.

2) Open *sparkfun_boards.txt* and copy the contents of the document.

3) Paste the bottom of the *boards.txt* file within the Adafruit nRF52 core installation on your computer.  
**Windows**:  
`%LOCALAPPDATA%\Arduino15\packages\adafruit\hardware\nrf52\<version>\boards.txt`  
**OS X**:  
`~/Library/Arduino15/packages/adafruit/hardware/nrf52/<version>\boards.txt`  
**Linux**:  
`~/.arduino15/packages/adafruit/hardware/nrf52/<version>\boards.txt`

4) Open the *variants* folder.

5) Copy the *sparkfun_nrf52840_mini* folder to the variants folder within the Adafruit nRF52 core installation on your computer.  
**Windows**:  
`%LOCALAPPDATA%\Arduino15\packages\adafruit\hardware\nrf52\<version>\variants`  
**OS X**:  
`~/Library/Arduino15/packages/adafruit/hardware/nrf52/<version>\variants`  
**Linux**:  
`~/.arduino15/packages/adafruit/hardware/nrf52/<version>\variants`

6) Restart the Arduino IDE.

If you look under **Tools** > **Board** > **Adafruit nRF52** and see *Sparkfun Pro nRF52840 Mini* at the bottom of the list, the modification of the board library worked correctly.
  
</br>

## Running the Code

## Uploading new/updated code to a board

1) Open '*ear_stim_project/ear_stim/ear_stim.ino*' in the Arduino IDE.

2) Create the circuit as shown in circuit_diagram.png.

3) Ensure the power switch on Sparkfun nRF52840 Pro Mini is turned on and connect the board to your computer with a USB-A to micro-USB cable.

4) Go to **Tools** > **Board** > **Adafruit nRF52** and select *Sparkfun Pro nRF52840 Mini*.

5) Go to **Tools** > **Port** and select the port for board. Unless you have multiple Arduino boards connected to your computer, this will most likely be the only port that shows up.  
If you do not see any ports this is probably because your USB cable only provides power and not data transmission. You'll need a cable that can do both

6) Enter bootloader mode on the board by either a) double tapping the *reset pin* or b) holding *pin 13* while tapping the *reset pin*.  
The board will indicate that it is in bootloader mode by flashing a blue LED on *pin 7* (in the middle of the board).

7) Click the '*Upload*' button at the top of Arduino IDE (or press CTRL+U) to begin the process of loading new code to the board.
