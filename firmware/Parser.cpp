#include "Parser.h" 

boolean allAxesDone(Axis axes[]) {
    // int axesLength = sizeof(axes) / sizeof(axes[0]);
    int axesLength = 6;
    for(int i = 0; i < axesLength; i++) {
        if(axes[i].moveRequired()) {
            Serial.println("Axis " + String(i) + " not finished!");
            return false;
        }
    }
    return true;
}

void runUntilFinished(Axis axes[]) {
    // int axesLength = sizeof(axes) / sizeof(axes[0]);
    int axesLength = 6;
    while(!allAxesDone(axes)) {
        for(int i = 0; i < axesLength; i++) {
            axes[i].stepTowardTarget();
        }
        Serial.println("Moving axes...");
    }
}

void parseG0(Axis axes[], String command) {
    String leftToParse = command;
    int nextSpace = leftToParse.indexOf(' ');
    Serial.println("Next Space " + String(nextSpace));
    while(nextSpace != -1) {
        char axis = leftToParse.charAt(0);

        float value = leftToParse.substring(1, nextSpace).toInt();

        Serial.println("Axis " + String(axis) + " to:" + String(value));
        value = value * -1; // flip so positive = away from motor
        // Axis toMove = getAxisByName(axes, axis);
        // toMove.setTargetPosition(value);

        // wtf?
        int axesLength = 6;
        for(int i = 0; i < axesLength; i++) {
            Serial.println("Identifier=" + String(axes[i].getIdentifier()));
            if(axes[i].getIdentifier() == axis) {
                Serial.println("Returning Axis " + String(i));
                axes[i].setTargetPosition(value);
            }
        }



        // break;

        if(nextSpace + 1 == leftToParse.length()) {
            break;
        }
        leftToParse = leftToParse.substring(nextSpace+1);
        Serial.println("LeftToParse" + leftToParse);

        // if(axis == 'X') {
        //     break;
        // }
        // break;
        nextSpace = leftToParse.indexOf(' ');
        Serial.println("Next Space " + String(nextSpace));
    }
    runUntilFinished(axes);
    Serial.println("Done movement!");
}

void parseLimitSwitch(String command) {
    Serial.println("Testing pin " + command);
    if(command == "0") {
        testLimitSwitch(xLimitSwitchPin);
    }
    else if(command == "1") {
        testLimitSwitch(yLimitSwitchPin);
    }
    else if(command == "2") {
        testLimitSwitch(z0LimitSwitchPin);
    }
    else if(command == "3") {
        testLimitSwitch(zLimitSwitchPin);
    }
}

void parseGCode(Axis axes[], String line) {
    int lineLength = line.length();
    if(lineLength < 2) {
        return;
    }

    String command = line.substring(0, 2);

    if(command == "G0") {
        Serial.println("Parsing G0...");
        String commands = line.substring(3);
        Serial.println("Commands:" + commands);
        parseG0(axes, commands+" ");
    }
    else if(command == "H0") {
        Serial.println("Homing printer...");
        homeAxes(axes);
    }
    else if(command == "T1") {
        Serial.println("Laser ON!");
        digitalWrite(laserPin, HIGH);
    }
    else if(command == "T0") {
        Serial.println("Laser OFF!");
        digitalWrite(laserPin, LOW);
    }

    else if(command == "L0") {
        parseLimitSwitch(line.substring(3, 4));
    }
    else if(command == "SX") {
        Axis xAxis = getAxisByName(axes, 'X');
        Serial.println("Got X Axis by name!");
        for(int i = 0; i < 5 * stepsPerRevolution; i++) {
            xAxis.step(1);
        }
        Serial.println("Done stepping x-axis!");
    }
}
