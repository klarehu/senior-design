//#include <DRV8834.h>
//#include <DRV8825.h>
//#include <MultiDriver.h>
//#include <A4988.h>
//#include <SyncDriver.h>
//#include <BasicStepperDriver.h>
//#include <DRV8880.h>
//#include "Printer.h"
//
//#define dirPin 2
//#define stepPin 3
//
//#define dirPin2 4
//#define stepPin2 5
//
//#define dirPin3 6
//#define stepPin3 7
//
//#define dirPin4 8
//#define stepPin4 9
//
//#define dirPin5 10
//#define stepPin5 11
//
//#define stepsPerRevolution 200
//
//void setup() {
//  // Declare pins as output:
//  pinMode(stepPin, OUTPUT);
//  pinMode(dirPin, OUTPUT);
//
//  pinMode(stepPin2, OUTPUT);
//  pinMode(dirPin2, OUTPUT);
//
//  pinMode(stepPin3, OUTPUT);
//  pinMode(dirPin3, OUTPUT);
//
//  pinMode(stepPin4, OUTPUT);
//  pinMode(dirPin4, OUTPUT);
//
//  pinMode(stepPin5, OUTPUT);
//  pinMode(dirPin5, OUTPUT);
//}
//void loop() {
//  delay(1000);
//  // Set the spinning direction clockwise:
//  digitalWrite(dirPin, HIGH);
//  digitalWrite(dirPin2, HIGH);
//  digitalWrite(dirPin3, HIGH);
//  digitalWrite(dirPin4, HIGH);
//  digitalWrite(dirPin5, HIGH);
//  // Spin the stepper motor 5 revolutions fast:
//  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
//    // These four lines result in 1 step:
//    digitalWrite(stepPin, HIGH);
//    digitalWrite(stepPin2, HIGH);
//    digitalWrite(stepPin3, HIGH);
//    digitalWrite(stepPin4, HIGH);
//    digitalWrite(stepPin5, HIGH);
//    delayMicroseconds(500);
//    digitalWrite(stepPin, LOW);
//    digitalWrite(stepPin2, LOW);
//    digitalWrite(stepPin3, LOW);
//    digitalWrite(stepPin4, LOW);
//    digitalWrite(stepPin5, LOW);
//    delayMicroseconds(500);
//  }
//  delay(1000);
//  // Set the spinning direction counterclockwise:
//  digitalWrite(dirPin, LOW);
//  digitalWrite(dirPin2, LOW);
//  digitalWrite(dirPin3, LOW);
//  digitalWrite(dirPin4, LOW);
//  digitalWrite(dirPin5, LOW);
//  //Spin the stepper motor 5 revolutions fast:
//  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
//    // These four lines result in 1 step:
//    digitalWrite(stepPin, HIGH);
//    digitalWrite(stepPin2, HIGH);
//    digitalWrite(stepPin3, HIGH);
//    digitalWrite(stepPin4, HIGH);
//    digitalWrite(stepPin5, HIGH);
//    delayMicroseconds(500);
//    digitalWrite(stepPin, LOW);
//    digitalWrite(stepPin2, LOW);
//    digitalWrite(stepPin3, LOW);
//    digitalWrite(stepPin4, LOW);
//    digitalWrite(stepPin5, LOW);
//    delayMicroseconds(500);
//  }
//  delay(1000);
//}
