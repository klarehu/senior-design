#include "Sequences.h"

#define LimitSwitchPull HIGH
#define LimitSwitchOppositePull LOW

void homeYAxis(Axis axes[]) {
    Axis yAxis = getAxisByName(axes, 'Y');
    Axis uAxis = getAxisByName(axes, 'U');
    int yState;
    int uState;

    // Serial.println("Homing Axis Y and U");

    while(1) {
        yState = digitalRead(yLimitSwitchPin);
        uState = digitalRead(yLimitSwitchPin);
        if(yState == LimitSwitchPull) {
            yAxis.step(1);
        }
        if(uState == LimitSwitchPull) {
            uAxis.step(1);
        }

        if(yState == LimitSwitchOppositePull && uState == LimitSwitchOppositePull) {
            break;
        }
    }
    // Serial.println("AXES Y AND U HOMED");
    yAxis.reset();
    uAxis.reset();
}

void homeGenericAxis(Axis axes[], char axisName, int limitSwitchPin) {
    // Serial.println("Homing Axis " + String(axisName));
    Axis axis = getAxisByName(axes, axisName);
    while(digitalRead(limitSwitchPin) == LimitSwitchPull) {
        axis.step(1);
    }
    // Serial.println("HOMED AXIS " + String(axisName));
    axis.reset();
}

void homeXAxis(Axis axes[]) {
    homeGenericAxis(axes, 'X', xLimitSwitchPin);
}

void homeZAxis(Axis axes[]) {
    homeGenericAxis(axes, 'Z', z0LimitSwitchPin);
}

void homeAxes(Axis axes[]) {
    homeYAxis(axes);
    homeXAxis(axes);
    homeZAxis(axes);
}

void testLimitSwitch(int switchPin) {
    while(digitalRead(switchPin) == LimitSwitchPull) {
        continue;
    }
    // Serial.println("Limit switch pin activated!" + String(switchPin));
}
