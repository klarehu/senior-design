#include "ToF.h"


void distanceSensing() {
    // initial roller radius in mm
    uint8_t rollerRad = 50;

    // initialilze angle change given a certain roller radius
    float changeAngle = 0;

    // initialize step angle of the roller motors
    // angle = 360/number of steps it takes for one rev
    //uint8_t stepAngle = 360/;


    // read the starting distance of the rollers
    uint8_t startDistance = tof1.readrange();
  
    // assess the status of the time of flight sensor
    uint8_t status = tof1.readRangeStatus();
    if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
    Serial.println("System error");
    }
    else if (status == VL6180X_ERROR_ECEFAIL) {
        Serial.println("ECE failure");
    }
    else if (status == VL6180X_ERROR_NOCONVERGE) {
        Serial.println("No convergence");
    }
    else if (status == VL6180X_ERROR_RANGEIGNORE) {
        Serial.println("Ignoring range");
    }
    else if (status == VL6180X_ERROR_SNR) {
        Serial.println("Signal/Noise error");
    }
    else if (status == VL6180X_ERROR_RAWUFLOW) {
        Serial.println("Raw reading underflow");
    }
    else if (status == VL6180X_ERROR_RAWOFLOW) {
        Serial.println("Raw reading overflow");
    }
    else if (status == VL6180X_ERROR_RANGEUFLOW) {
        Serial.println("Range reading underflow");
    }
    else if (status == VL6180X_ERROR_RANGEOFLOW) {
        Serial.println("Range reading overflow");
    }

    while (status == VL6180X_ERROR_NONE && changeAngle < 0.5) {

        // troubleshooting - find out the range value
        Serial.print("Range: "); Serial.println(startDistance);

        uint8_t range = tof1.readrange();
        uint8_t diff = abs(startDistance - range);

        float currentLength = rollerRad * stepAngle;

        changeAngle = currentLength / (rollerRad - diff);

        delay(50);

    }

    return(changeAngle);


}
