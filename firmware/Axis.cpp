#include "Axis.h"

Axis::Axis(char idenfitier, int dirPin, int stepPin, int delayTime) {
	__identifier = idenfitier;
	__dirPin = dirPin;
	__stepPin = stepPin;
	__delayTime = delayTime;
	pinMode(__stepPin, OUTPUT);
	pinMode(__dirPin, OUTPUT);
	digitalWrite(__stepPin, LOW);
	digitalWrite(__dirPin, LOW);
    reset();
}

void Axis::reset() {
	__position = 0.0;
	__target = 0.0;
}

void Axis::setTargetPosition(int target) {
	__target = target;
}

boolean Axis::stepTowardTarget() {
	return true;
}

void Axis::step(int direction) {
	__target += direction;

	if(direction == 1) {
		digitalWrite(__dirPin, HIGH);
	}
	else if(direction == -1) {
		digitalWrite(__dirPin, LOW);
	}

	digitalWrite(__stepPin, HIGH);
	delayMicroseconds(__delayTime);
	digitalWrite(__stepPin, LOW);
}

int Axis::getStepPin() {
	return __stepPin;
}

int Axis::getDirPin() {
	return __dirPin;
}

int Axis::getDelayTime() {
	return __delayTime;
}

boolean Axis::moveRequired() {
	return __position == __target;
}

char Axis::getIdentifier() {
	return __identifier;
}

