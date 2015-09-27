/*
 * DriveTrain.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: Ryan
 */

#include "DriveTrain.h"

DriveTrain::DriveTrain():
leftVictor1((uint32_t) 1),
leftVictor2((uint32_t) 2),

rightVictor1((uint32_t) 3),
rightVictor2((uint32_t) 4),


leftPIDController1(0,0,0,*leftEncoder,*leftVictor1),
leftPIDController2(0,0,0,*leftEncoder,*leftVictor2),

rightPIDController1(0,0,0,*rightEncoder,*rightVictor1),
rightPIDController2(0,0,0,*rightEncoder,*rightVictor2),

leftEncoder((uint32_t) 1, (uint32_t) 2),
rightEncoder((uint32_t) 3, (uint32_t)4)
{}

DriveTrain::~DriveTrain() {

}

void DriveTrain::driveDistance(float distance) {
	leftPIDController1.SetSetpoint(distance);
	leftPIDController2.SetSetpoint(distance);

	rightPIDController1.SetSetpoint(distance);
	rightPIDController2.SetSetpoint(distance);
}

void DriveTrain::setSpeed(float rotateSpeed,float moveSpeed) {
	setLeft(-(moveSpeed - rotateSpeed));
	setRight(moveSpeed + rotateSpeed);
}

void DriveTrain::setLeft(float speed)
{
	leftVictor1.Set(speed);
	leftVictor2.Set(speed);

}
void DriveTrain::setRight(float speed)
{
	rightVictor1.Set(speed);
	rightVictor2.Set(speed);

}
