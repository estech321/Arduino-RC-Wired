/* This code controls my wired Arduino-based RC car. It uses the OSEPP Motor sheild and the Adafruit Motor Sheild library to drive 4 DC motors based on inputs on a wired controller.
Be sure to use an Arduino MEGA 2560 so there's enough pins for everything.

Created by Eric (esTech) in 2023 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see https://www.gnu.org/licenses/.
*/

// Import libraries
#include <Arduino.h> // Because I used PlatformIO, I have to import the Arduino library.
#include <AFMotor.h> // This imports the library used by the sheild

// Constructing/defining DC motors:
AF_DCMotor fl(1);
AF_DCMotor fr(2);
AF_DCMotor bl(3);
AF_DCMotor br(4);

// Define remote control pins:
#define fwdButton 50 // Forward pin is orange
#define backButton 51 // Backward pin is green
#define leftButton 52 // Left pin is red
#define rightButton 53 // Right pin is yellow

// Define LED pins:
#define flLED 49
#define frLED 48
#define tflLED 47
#define tfrLED 46
#define tblLED 45
#define tbrLED 44

// Button state variables
int fwdButtonState = 0;
int backButtonState = 0;
int leftButtonState = 0;
int rightButtonState = 0;


void setup() {
  // Set remote pins as inputs
  pinMode(fwdButton, INPUT);
  pinMode(backButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  
  // Set LED pins as outputs
  pinMode(flLED, OUTPUT);
  pinMode(frLED, OUTPUT);
  pinMode(tflLED, OUTPUT);
  pinMode(tfrLED, OUTPUT);
  pinMode(tblLED, OUTPUT);
  pinMode(tbrLED, OUTPUT);
    
  // Set motors' default speed
  fl.setSpeed(200);
  fr.setSpeed(200);
  bl.setSpeed(200);
  br.setSpeed(200);
}


void loop() {
  // Read the button states
  fwdButtonState = digitalRead(fwdButton);
  backButtonState = digitalRead(backButton);
  leftButtonState = digitalRead(leftButton);
  rightButtonState = digitalRead(rightButton);

  // Move based on button states
  if (fwdButtonState == HIGH) {
    moveForward();
    digitalWrite(flLED, HIGH);
    digitalWrite(frLED, HIGH);
    digitalWrite(tflLED, HIGH);
    digitalWrite(tfrLED, HIGH);
  } else if (backButtonState == HIGH) {
    moveBackward();
    digitalWrite(tblLED, HIGH);
    digitalWrite(tbrLED, HIGH);
  } else if (leftButtonState == HIGH) {
    moveLeft();
    digitalWrite(flLED, HIGH);
    digitalWrite(tflLED, HIGH);
    digitalWrite(tblLED, HIGH);
  } else if (rightButtonState == HIGH) {
    moveRight();
    digitalWrite(frLED, HIGH);
    digitalWrite(tfrLED, HIGH);
    digitalWrite(tbrLED, HIGH);
  } else {
    moveStop();
    digitalWrite(flLED, LOW);
    digitalWrite(frLED, LOW);
    digitalWrite(tflLED, LOW);
    digitalWrite(tfrLED, LOW);
    digitalWrite(tblLED, LOW);
    digitalWrite(tbrLED, LOW);
  }

}

void moveTest()
{
  moveForward();
  delay(1500);
  moveBackward();
  delay(1500);
  moveLeft();
  delay(1500);
  moveRight();
  delay(1500);
}

void moveStop()
{
  // Turn off motors
  fl.run(RELEASE);
  fr.run(RELEASE);
  bl.run(RELEASE);
  br.run(RELEASE);
}

void moveRight()
{
  // Turn right
  fl.run(BACKWARD);
  fr.run(FORWARD);
  bl.run(BACKWARD);
  br.run(FORWARD);
}

void moveLeft()
{
  // Turn left
  fl.run(FORWARD);
  fr.run(BACKWARD);
  bl.run(FORWARD);
  br.run(BACKWARD);
}

void moveBackward()
{
  // Move backward
  fl.run(BACKWARD);
  fr.run(BACKWARD);
  bl.run(BACKWARD);
  br.run(BACKWARD);
}

void moveForward()
{
  // Move forward
  fl.run(FORWARD);
  fr.run(FORWARD);
  bl.run(FORWARD);
  br.run(FORWARD);
}