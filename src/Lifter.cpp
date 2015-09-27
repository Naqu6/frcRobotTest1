/*
 * Lifter.cpp
 *
 *  Created on: Sep 27, 2015
 *      Author: Ryan
 */

#include <Lifter.h>

Lifter::Lifter():

	lifterVictor1((uint32_t) 5),
	lifterVictor2((uint32_t) 6),

	lifterEncoder((uint32_t) 1, (uint32_t) 2),

	lifterPIDController1(0,0,0,*lifterVictor1,*lifterEncoder),
	lifterPIDController2(0,0,0,*lifterVictor2,*lifterEncoder)
	{}



Lifter::~Lifter() {
	// TODO Auto-generated destructor stub
}

void DriveTrain::setLifter(float value) {
	if (lifterState == PID_CONTROL) {
		if ((lifterEncoder.GetStopped() == true) && (getLifterError())) {
			lifterState = TELEOP;
		}
	} else {
		setLifterVictors(value);
		lifterState = PID_CONTROL;
	}
}

bool DriveTrain::getLifterError() {
	int lifter1Error = lifterPIDController1.GetError();
	int lifter2Error = lifterPIDController2.GetError();
	if (std::max(lifter1Error,lifter2Error)) {
		return true;
	} else {
		return false;
	}


}
void DriveTrain::setLifterVictors(float value) {
	lifterVictor2.Set(value);
	lifterVictor1.Set(value);
}


