#include "Parser.h" 

boolean allAxesDone(Axis axes[]) {
    int axesLength = sizeof(axes) / sizeof(axes[0]);
    for(int i = 0; i < axesLength; i++) {
        if(axes[i].moveRequired()) {
            return false;
        }
    }
    return true;
}

void runUntilFinished(Axis axes[]) {
    int axesLength = sizeof(axes) / sizeof(axes[0]);
    while(!allAxesDone(axes)) {
        for(int i = 0; i < axesLength; i++) {
            axes[i].stepTowardTarget();
        }
    }
}

void parseG0(Axis axes[], String command) {
    String leftToParse = command;
    int nextSpace = leftToParse.indexOf(' ');
    while(nextSpace != -1) {
        char axis = leftToParse.charAt(0);
        float value = leftToParse.substring(1, nextSpace).toFloat();
        Axis toMove = getAxisByName(axes, axis);
        toMove.setTargetPosition(value);

        Serial.println("Axis " + String(axis) + ":" + String(value));

        leftToParse = leftToParse.substring(nextSpace+1);
        nextSpace = leftToParse.indexOf(' ');
    }
    runUntilFinished(axes);
}

void parseGCode(Axis axes[], String line) {
    int lineLength = line.length();
    if(lineLength < 2) {
        return;
    }

    if(line.substring(0, 2) == "G0") {
        Serial.println("Parsing G0...");
        String commands = line.substring(3);
        parseG0(axes, commands+" ");
    }
}
