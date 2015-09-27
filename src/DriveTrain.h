/*
 * DriveTrain.h
 *
 *  Created on: Sep 20, 2015
 *      Author: Ryan
 */

#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_
#include <Victor.h>
#include <Encoder.h>
#include <PIDController.h>


class DriveTrain {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void setSpeed(float fowardX,float fowardY);
	void driveDistance(float distance);
	

private:
	Victor leftVictor1;
	Victor leftVictor2;

	Victor rightVictor1;
	Victor rightVictor2;

	Victor lifterVictor1;
	Victor lifterVictor2;

	Encoder leftEncoder;
	Encoder rightEncoder;

	Encoder lifterEncoder;

	PIDController leftPIDController1;
	PIDController leftPIDController2;

	PIDController rightPIDController1;
	PIDController rightPIDController2;

	void setRight(float speed);
	void setLeft(float speed);
};

#endif /* SRC_DRIVETRAIN_H_ */
