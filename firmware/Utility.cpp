#include "Utility.h"

Axis getAxisByName(Axis axes[], char c) {
    int axesLength = sizeof(axes) / sizeof(axes[0]);
    for(int i = 0; i < axesLength; i++) {
        if(axes[i].getIdentifier() == c) {
            return axes[i];
        }
    }
    Serial.println('ERROR FINDING AXIS BY IDENTIFIER');
    return axes[0];
}
