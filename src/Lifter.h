/*
 * Lifter.h
 *
 *  Created on: Sep 27, 2015
 *      Author: Ryan
 */

#include <Victor.h>
#include <Encoder.h>
#include <PIDController.h>

#ifndef SRC_LIFTER_H_
#define SRC_LIFTER_H_

class Lifter {
public:
	Lifter();
	virtual ~Lifter();
	void setLifter(float value);

private:
	Victor lifterVictor1;
	Victor lifterVictor2;

	PIDController lifterPIDController1;
	PIDController lifterPIDController2;

	Encoder lifterEncoder;

	enum State{
				TELEOP,
				PID_CONTROL
			};

		State lifterState;

	void setLifterVictors(float value);
	bool getLifterError();
};

#endif /* SRC_LIFTER_H_ */
