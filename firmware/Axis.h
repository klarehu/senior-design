#include <Arduino.h>

#ifndef AXIS_H_
#define AXIS_H_

class Axis {
public:
    Axis(char identifier, int dirPin, int stepPin, int delayTime);
    void reset();
    void setTargetPosition(int target);
    boolean stepTowardTarget();
    void step(int direction);
    int getStepPin();
    int getDirPin();
    int getDelayTime();
    boolean moveRequired();
    char getIdentifier();

private:
    char __identifier;
    int __dirPin;
    int __stepPin;
    int __delayTime;
    float __position;
    float __target;
};

#endif
