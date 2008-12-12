/*
	Mobot.cpp - Mobot library for Arduino
	Created by Rich Hong, December 11, 2008
*/
#include "Mobot.h"

Mobot::Mobot(int E1, int E2, int I1, int I2, int I3, int I4){
	pinMode(E1, OUTPUT);
	pinMode(E2, OUTPUT);
	pinMode(I1, OUTPUT);
	pinMode(I2, OUTPUT);
	pinMode(I3, OUTPUT);
	pinMode(I4, OUTPUT);

	_E1 = E1;
	_E2 = E2;
	_I1 = I1;
	_I2 = I2;
	_I3 = I3;
	_I4 = I4;
}

void Mobot::forward(int speed) {
	enableMotors();
	leftMotor(0, speed);
	rightMotor(0, speed);
}

void Mobot::enableMotors() {
	digitalWrite(_E1, HIGH);
	digitalWrite(_E2, HIGH);
}

void Mobot::disableMotors() {
	digitalWrite(_E1, LOW);
	digitalWrite(_E2, LOW); 
}

void Mobot::leftMotor(int dir, int speed) {
	if(speed == 0) {
		//brake the motor
		leftMotorBrake();
	}else{
		if(dir == 0) {
			digitalWrite(_I4, HIGH);
			analogWrite(_I3, 255 - speed);
		}else{
			digitalWrite(_I4, LOW);
			analogWrite(_I3, speed);
   }
	}
}

void Mobot::leftMotorBrake() {
	digitalWrite(_I4, LOW);
	digitalWrite(_I3, LOW);
}

void Mobot::rightMotor(int dir, int speed) {
	if(speed == 0) {
		//brake the motor
		rightMotorBrake();
	}else{
		//go forward
		if(dir == 0) {
			digitalWrite(_I2, LOW);
			analogWrite(_I1, speed);
		}else{
			//go backward
			digitalWrite(_I2, HIGH);
			analogWrite(_I1, 255 - speed);
		}
	}
}

void Mobot::rightMotorBrake() {
	digitalWrite(_I1, LOW);
	digitalWrite(_I2, LOW); 
}

void Mobot::stop() {
	leftMotorBrake();
	rightMotorBrake(); 
}

void Mobot::turnLeft() {
	rightMotor(0, 255);
	digitalWrite(_E2, LOW);
}

