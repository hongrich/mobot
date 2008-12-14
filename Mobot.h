/*
	Mobot.h - Mobot library for Arduino
	Created by Rich Hong, Decemeber 11, 2008
*/
#ifndef _MOBOT_H
#define _MOBOT_H

#include "WProgram.h"

class Mobot {
	public:
		Mobot(int E1, int E2, int I1, int I2, int I3, int I4);

		void goFor0(int msec, Mobot *m, void (Mobot::*fn)());
		void goFor1(int msec, Mobot *m, void (Mobot::*fn)(int), int arg1);
		void goFor2(int msec, Mobot *m, void (Mobot::*fn)(int,int), int arg1, int arg2);

		void enableMotors();
		void disableMotors();
		void leftMotorBrake();
		void rightMotorBrake();
		void leftMotor(int dir, int speed);
		void rightMotor(int dir, int speed);

		void stop();

		/* move the mobot forward, speed can range from 0 - 255 */
		void forward(int speed = 255);
		void spinLeft(int speed = 255);
		void spinRight(int speed = 255);
		void turnLeft();

	private:
		int _E1;
		int _E2;
		int _I1;
		int _I2;
		int _I3;
		int _I4;
};

#endif
