#include "WPILib.h"
#include "GamePadL.h"

const FSpeed = 1.0;


class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot;
	GamepadL gamepad; 
	Jaguar shooter;
	Compressor comp;
	Relay rel;
	float speed;
	const float shooterStep;
	Relay::Value pistonPosition;
	float leftSpeed;
	float rightSpeed;
public:
RobotDemo(void):
myRobot(2, 1),
gamepad(1),
comp(1,1),
shooter(3),
rel(2),
speed(0),
shooterStep(0.01),
pistonPosition(Relay::kOff),
leftSpeed(0.0),
rightSpeed(0.0)
{
	myRobot.SetExpiration(0.1);
	comp.Start();
	myRobot.SetSafetyEnabled(true);
}

void mechanismSet()
{
	shooter.Set(speed);
	myRobot.TankDrive(leftSpeed, rightSpeed);
	rel.Set(pistonPosition);
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
	if (speed > FSpeed)
	{
		speed = FSpeed;
	} 
	if (speed < -FSpeed)
	{
		speed = -FSpeed;
	}
	return speed;
}

void OperatorControl(void)
{

	while (IsOperatorControl())
	{
		
		//RegulateSpeed(speed);
		//if (leftstick.GetY() == 1 && rightstick.GetY() == 1)
		leftSpeed= gamepad.GetLeftY()*(-1);
		rightSpeed = gamepad.GetRightY();
		
		if (gamepad.GetRawButton(5))
		{
			pistonPosition = Relay::kReverse;
		}
		else{
			pistonPosition = Relay::kForward;
		}
		
		if (gamepad.GetRawButton(6))
		{
			speed+=shooterStep;
		}
		if (gamepad.GetRawButton(8))
		{
			speed -=shooterStep;
		}
		if (gamepad.GetRawButton(1))
		{
			speed=-1;
		}
		if (gamepad.GetRawButton(2))
		{
			speed=0;
		}
		mechanismSet();
		Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
