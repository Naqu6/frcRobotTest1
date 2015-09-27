#include "WPILib.h"
#include "DriveTrain.h"
#include <Victor.h>
#include <Joystick.h>

class Robot: public IterativeRobot
{
	Robot::Robot():

	driveTrain(),
	joy1((uint32_t) 0),
	joy2((uint32_t) 1)
	{}



private:
	Joystick joy1;
	Joystick joy2;

	DriveTrain driveTrain;

	void RobotInit()
	{


	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		driveTrain.setSpeed(joy1.GetX(),joy2.GetY());

	}

	void TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
