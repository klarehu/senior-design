#include "Parser.h"

Axis findStateByIdentifier(Axis axes[], char c) {
    int stateLength = sizeof(axes) / sizeof(axes[0]);
    for(int i = 0; i < stateLength; i++) {
        if(axes[i].getIdentifier() == c) {
            return axes[i];
        }
    }
    Serial.println('ERROR FINDING AXIS BY IDENTIFIER');
    return axes[0];
}

void parseGCode(Axis axes[], String line) {
    int lineLength = line.length();
    if(lineLength < 2) {
        return;
    }

    Serial.println(line.substring(0, 2));

    if(line.substring(0, 3) == 'G0') {
        Serial.println("Got a G0!");
        Serial.println(line);
    }
}
