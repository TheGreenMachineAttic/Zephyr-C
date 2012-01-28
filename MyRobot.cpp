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
myRobot(1, 2, 3, 4),
gamepad(1),
shooter(5),
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
		myRobot.TankDrive(gamepad.GetLeftY(), gamepad.GetRightY()); 
		RegulateSpeed(speed);
		
		if (gamepad.GetRawButton(7))
		{
			rel.Set(Relay::kForward);
		}
		
		if (gamepad.GetRawButton(8))
		{
			shooter.Set(0.435);
		}
		Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
