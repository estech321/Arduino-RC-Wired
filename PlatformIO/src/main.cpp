/* The official code that ACTUALLY works to control my wired Arduino-based RC car. It uses the OSEPP Motor sheild and the Adafruit Motor Sheild library, which is depricated but is the library required to use my sheild. I created this program in VS Code using PlatformIO.
Be sure to use an Arduino MEGA 2560 so there's enough pins for everything.
Created by Eric (esTech) in 2023 */

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
  } else if (backButtonState == HIGH) {
    moveBackward();
  } else if (leftButtonState == HIGH) {
    moveLeft();
  } else if (rightButtonState == HIGH) {
    moveRight();
  } else {
    moveStop();
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