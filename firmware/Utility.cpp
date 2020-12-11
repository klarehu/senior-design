#include "Utility.h"

Axis getAxisByName(Axis axes[], char c) {
    // int axesLength = sizeof(axes) / sizeof(axes[0]);
    Serial.println("Getting axis by identifier");
    int axesLength = 6;
    for(int i = 0; i < axesLength; i++) {
    	Serial.println("Idenfitier=" + String(axes[i].getIdentifier()));
        if(axes[i].getIdentifier() == c) {
            Serial.println("Returning Axis " + String(i));
            return axes[i];
        }
    }
    Serial.println("ERROR FINDING AXIS BY IDENTIFIER");
    return axes[0];
}
