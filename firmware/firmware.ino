#include <DRV8834.h>
#include <DRV8825.h>
#include <MultiDriver.h>
#include <A4988.h>
#include <SyncDriver.h>
#include <BasicStepperDriver.h>
#include <DRV8880.h>
#include "Axis.h"
#include "Definitions.h"
#include "Parser.h"

Axis xAxis = Axis('X', xDirPin, xStepPin, delayTime);
Axis yAxis = Axis('Y', yDirPin, yStepPin, delayTime);
Axis zAxis = Axis('Z', zDirPin, zStepPin, delayTime);
Axis collectorAxis = Axis('E', collectorDirPin, collectorStepPin, delayTime);
Axis unrollerAxis = Axis('F', unrollerDirPin, unrollerStepPin, delayTime);

Axis axes[] = {xAxis, yAxis, zAxis, collectorAxis, unrollerAxis};

String serialLine;
char delimiter = '\n';
String OK = "OK";

void parse(char c) {
    if(c == 'X') {
        return xAxis;
    }
    else if(c == 'Y') {
        return yAxis;
    }
    else if(c == 'Z') {
        return zAxis;
    }
    else if(c == 'E') {
        return collectorAxis;
    }
}

void sendOK() {
    Serial.println(OK);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Firmware Loaded.");
}


void loop() {
    if(Serial.available() > 0)
    {
        serialLine = Serial.readStringUntil(delimiter);
        parseGCode(axes, serialLine);
        sendOK();
    }
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
}
