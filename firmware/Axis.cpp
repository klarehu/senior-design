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
	this->__target = 0.0;
	this->__moveRequired = false;
}

void Axis::setTargetPosition(int target) {
	this->__target = target;
	// Serial.println("Target = "+ String(this->__target));
	this->__moveRequired = this->__target != __position;
	// if(this->__target != __position) {
	// 	this->__moveRequired = true;
		// Serial.println("MOVE REQUIRED BY AXIS " + String(__identifier) + "    " + String((int)this));
	// }
	// else {
	// 	this->__moveRequired = false;
	// }
}

void Axis::stepTowardTarget() {
	this->__moveRequired = this->__target != __position;
	if(!this->__moveRequired) {
		return;
	}
	// Serial.println("STEPPING AXIS");
	step((this->__target > __position) ? 1 : -1);
}

void Axis::step(int direction) {
	// Serial.println("Step direction " + String(direction));
	this->__position += direction;
	// Serial.println("Position:" + String(this->__position) + "  Target:" + String(this->__target) + "    Axis:" + this->__identifier);

	digitalWrite(__dirPin, (direction == 1) ? HIGH : LOW);

	digitalWrite(__stepPin, HIGH);
	delayMicroseconds(__delayTime);
	digitalWrite(__stepPin, LOW);
	delayMicroseconds(__delayTime);
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
	// Serial.println("Querying Axis " + String(__identifier));;
	// Serial.println("Target = "+ String(this->__target) + "   " + String(this->__moveRequired));
	// Serial.println(String((int)this));
	return this->__moveRequired;
}

char Axis::getIdentifier() {
	return __identifier;
}

