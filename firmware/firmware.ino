#include <DRV8834.h>
#include <DRV8825.h>
#include <MultiDriver.h>
#include <A4988.h>
#include <SyncDriver.h>
#include <BasicStepperDriver.h>
#include <DRV8880.h>
#include <Wire.h>
#include "Adafruit_VL6180X.h"
#include "Axis.h"
#include "Definitions.h"
#include "Parser.h"
#include "Sequences.h"

// #define dirPin 0
// #define stepPin 1
// #define stepsPerRevolution 200
// void setup() {
//  // Declare pins as output:
//  pinMode(stepPin, OUTPUT);
//  pinMode(dirPin, OUTPUT);

//  digitalWrite(stepPin, LOW);
//  digitalWrite(dirPin, LOW);
// }
// void loop() {
 // delay(1000);
 // // Set the spinning direction clockwise:
 // digitalWrite(dirPin, HIGH);
 // // Spin the stepper motor 5 revolutions fast:
 // for (int i = 0; i < 5 * stepsPerRevolution; i++) {
 //   // These four lines result in 1 step:
 //   digitalWrite(stepPin, HIGH);
 //   delayMicroseconds(500);
 //   digitalWrite(stepPin, LOW);
 //   delayMicroseconds(500);
 // }
 // delay(1000);
 // // Set the spinning direction counterclockwise:
 // digitalWrite(dirPin, LOW);
 // //Spin the stepper motor 5 revolutions fast:
 // for (int i = 0; i < 5 * stepsPerRevolution; i++) {
 //   // These four lines result in 1 step:
 //   digitalWrite(stepPin, HIGH);
 //   delayMicroseconds(500);
 //   digitalWrite(stepPin, LOW);
 //   delayMicroseconds(500);
 // }
 // delay(1000);
// }


Axis xAxis = Axis('X', xDirPin, xStepPin, delayTime);
Axis yAxis = Axis('Y', yDirPin, yStepPin, delayTime);
Axis uAxis = Axis('U', uDirPin, uStepPin, delayTime);
Axis zAxis = Axis('Z', zDirPin, zStepPin, 1200);
Axis collectorAxis = Axis('E', collectorDirPin, collectorStepPin, delayTime);
Axis unrollerAxis = Axis('F', unrollerDirPin, unrollerStepPin, delayTime);

Axis axes[] = {xAxis, yAxis, uAxis, zAxis, collectorAxis, unrollerAxis};

Adafruit_VL6180X tof1 = Adafruit_VL6180X();

String serialLine;
char delimiter = '\n';
String OK = "OK";
int baudRate = 115200;

void setup() {
    Serial.begin(baudRate);
    Serial.println("Firmware Loaded.\nPrinter Ready.");
    pinMode(laserPin, OUTPUT);

    // Set the onboard LED on :)
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    tof1.begin();

    // while(true) {
    //     Serial.println(tof1.readRange());
    // }
}

void loop() {
    if(Serial.available() > 0)
    {
        serialLine = Serial.readStringUntil(delimiter);
        parseGCode(axes, serialLine);
        Serial.println(OK);
    }
}
