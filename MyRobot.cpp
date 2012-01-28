#include "WPILib.h"
#include "GamePadL.h"


class RobotDemo : public SimpleRobot
{
RobotDrive myRobot;
GamepadL gamepad; 
Joystick leftstick;
Joystick rightstick;
Jaguar leftjagFront; 
Jaguar rightjagFront;
Jaguar leftjagBack; 
Jaguar rightjagBack;
Jaguar shooter;
Compressor comp;
float speed;

public:
RobotDemo(void):
myRobot(1, 2),
gamepad(1),
leftstick(1),
rightstick(2),
leftjagFront(1),
rightjagFront(2),
leftjagBack(3),
rightjagBack(4),
comp(3)
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
		myRobot.TankDrive(leftstick.GetRawAxis(1), rightstick.GetRawAxis(2)); 
		RegulateSpeed(speed);
		if (leftstick.GetY() == 1 && rightstick.GetY() == 1)
		{
			leftjagBack.Set(speed);
			leftjagBack.Set(speed);
			rightjagFront.Set(speed);
			rightjagBack.Set(speed);
		}
		if (leftstick.GetY() == -1 || rightstick.GetY() == 1)
		{
			leftjagBack.Set(-speed);
			leftjagBack.Set(-speed);
			rightjagFront.Set(speed);
			rightjagBack.Set(speed);
		}
		if (leftstick.GetY() == 1 || rightstick.GetY() == -1)
		{
			leftjagBack.Set(speed);
			leftjagBack.Set(speed);
			rightjagFront.Set(-speed);
			rightjagBack.Set(-speed);
		}
		if (leftstick.GetY() == -1 && rightstick.GetY() == -1)
		{
			leftjagBack.Set(-speed);
			leftjagBack.Set(-speed);
			rightjagFront.Set(-speed);
			rightjagBack.Set(-speed);
		}
		
		comp.Start();
		
		if (gamepad.GetRawButton(7))
		{
			comp.Relay::kForward;
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
