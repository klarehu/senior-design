#include "Sequences.h"

void homeYAxis(Axis axes[]) {
    Axis yAxis = getAxisByName(axes, 'Y');
    Axis uAxis = getAxisByName(axes, 'U');
    int yState;
    int uState;

    while(1) {
        yState = digitalRead(yLimitSwitchPin);
        uState = digitalRead(yLimitSwitchPin);
        if(yState == LOW) {
            yAxis.step(-1);
        }
        if(uState == LOW) {
            uAxis.step(-1);
        }

        if(yState == HIGH && uState == HIGH) {
            break;
        }
    }
    yAxis.reset();
    uAxis.reset();
}

void homeGenericAxis(Axis axes[], char axisName, int limitSwitchPin) {
    Axis axis = getAxisByName(axes, axisName);
    while(digitalRead(limitSwitchPin) == LOW) {
        axis.step(-1);
    }
    axis.reset();
}

void homeXAxis(Axis axes[]) {
    homeGenericAxis(axes, 'X', xLimitSwitchPin);
}

void homeZAxis(Axis axes[]) {
    homeGenericAxis(axes, 'Z', zLimitSwitchPin);
}

void homeAxes(Axis axes[]) {
    homeYAxis(axes);
    homeXAxis(axes);
    homeZAxis(axes);
}
