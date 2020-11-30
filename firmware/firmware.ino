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
#include "Sequences.h"

Axis xAxis = Axis('X', xDirPin, xStepPin, delayTime);
Axis yAxis = Axis('Y', yDirPin, yStepPin, delayTime);
Axis uAxis = Axis('U', uDirPin, uStepPin, delayTime);
Axis zAxis = Axis('Z', zDirPin, zStepPin, delayTime);
Axis collectorAxis = Axis('E', collectorDirPin, collectorStepPin, delayTime);
Axis unrollerAxis = Axis('F', unrollerDirPin, unrollerStepPin, delayTime);

Axis axes[] = {xAxis, yAxis, uAxis, zAxis, collectorAxis, unrollerAxis};

String serialLine;
char delimiter = '\n';
String OK = "OK";
int baudRate = 9600;

void setup() {
    Serial.begin(baudRate);
    Serial.println("Firmware Loaded.\nHoming axes..");
    homeAxes(axes);
    Serial.println("Printer Ready.");
}

void loop() {
    if(Serial.available() > 0)
    {
        serialLine = Serial.readStringUntil(delimiter);
        parseGCode(axes, serialLine);
        Serial.println(OK);
    }
}
