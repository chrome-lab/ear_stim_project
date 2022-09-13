//****************************************************************************************************************//
//                                                                                                                //
// Maya Dunlap                                                                                                    //
// CHROME Lab - Ear Stim Project                                                                                  //
// PORTABLE & VARIABLE INTENSITY EAR STIM CODE                                                                    //
//                                                                                                                //
//      Purpose:                                                                                                  //
//               - Vibrate ERM at a simulated 2 Hz frequency                                                      //
//               - Vibrations turn on when a button is pressed                                                    //
//               - Vibrations turn off when a button is pressed a second time                                     //
//      Last Updated: 09/12/2022                                                                                  //
//      Version: 1.0.0                                                                                            //
//                                                                                                                //
//****************************************************************************************************************//


//********************************************* MAIN CODE ********************************************************//

////////////////// WORKSPACE SETUP //////////////////

// Install necessary libraries
#include "Adafruit_TinyUSB.h"

// Define pins
const int MTR_PIN = 5;
const int LED_PIN = 22;
const int BTN_PIN = 23;

// Define peripheral variables
int ON_PWM = 200;
const int OFF_PWM = 0;
volatile byte led_off = LOW;
volatile bool vib_on = false;
unsigned long lastSwitch = 0;

/////////////// USER DEFINED FUNCTION ///////////////

// FUNCTION: Create turn vibration state on or off
void switchMotorState(){
  if( millis() - lastSwitch > 10 ){
    vib_on = !vib_on;
    lastSwitch = millis();
  }
}

// FUNCTION: Generate simulated 2 Hz vibrations
void generateVibSignal(){
  static unsigned long lastTimeCheck = 0;

  // Turn on motor & wait 0.25 seconds
    analogWrite( MTR_PIN, ON_PWM );
    lastTimeCheck = millis();
    while (millis() - lastTimeCheck < 250 ){};
    
    // Turn off motor & wait 0.25 seconds
    analogWrite( MTR_PIN, OFF_PWM );
    lastTimeCheck = millis();
    while (millis() - lastTimeCheck < 250 ){}; 
}

///////////// REQUIRED ARDUINO FUNCTIONS ////////////

// FUNCTION: Run once when code begins
void setup() {
  // Initialize pins
  pinMode( MTR_PIN, OUTPUT );
  pinMode( LED_PIN, OUTPUT );
  pinMode( BTN_PIN, INPUT );
  analogWrite( MTR_PIN, OFF_PWM );
  digitalWrite( LED_PIN, led_off );
}

// FUNCTION: Run continuously after setup
void loop() {
  if( digitalRead( BTN_PIN ) == HIGH && !vib_on ){
    digitalWrite( LED_PIN, HIGH );
    switchMotorState();
  }
  else if( digitalRead( BTN_PIN ) == LOW && vib_on){
    switchMotorState();
    digitalWrite( LED_PIN, LOW );
  }

  if( vib_on ){
    generateVibSignal();
  }
}
