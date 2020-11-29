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

void setup() {
    Serial.begin(9600);
    Serial.println("Firmware Loaded.");
}

void loop() {
    if(Serial.available() > 0)
    {
        serialLine = Serial.readStringUntil(delimiter);
        parseGCode(axes, serialLine);
        Serial.println(OK);
    }
}
