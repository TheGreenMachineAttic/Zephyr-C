#include "WPILib.h"
#include "GamePadL.h"


class RobotDemo : public SimpleRobot
{
RobotDrive myRobot;
GamepadL gamepad; 
Jaguar shooter;
Compressor comp;
Relay rel;
float speed;

public:
RobotDemo(void):
myRobot(2,1),
gamepad(1),
shooter(3),
comp(1, 1),
rel(2)
{
	myRobot.SetExpiration(0.1);
}


void Autonomous(void)
{
	myRobot.SetSafetyEnabled(false);
	myRobot.Drive(0.5, 0.0); 
	Wait(2.0); //    for 2 seconds
	myRobot.Drive(0.0, 0.0);
}

float RegulateSpeed (float speed)
{
	if (speed > 1.0)
	{
		speed = 1.0;
	} 
	if (speed < -1.0)
	{
		speed = -1.0;
	}
	return speed;
}

void OperatorControl(void)
{ 
	myRobot.SetSafetyEnabled(true);
	while (IsOperatorControl())
	{
		myRobot.TankDrive((gamepad.GetLeftY()*(-1)), gamepad.GetRightY()); 
		//RegulateSpeed(speed);
		
		if (gamepad.GetRawButton(8))
		{
			rel.Set(Relay::kForward);
		}
		if (gamepad.GetRawButton(6))
		{
			rel.Set(Relay::kOff);
		}
		
		if (gamepad.GetRawButton(7))
		{
			shooter.Set(-0.5);
		}
		if (gamepad.GetRawButton(1))
		{
			shooter.Set(-1);
		}
		if (gamepad.GetRawButton(2))
		{
			shooter.Set(0);
		}
		Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
