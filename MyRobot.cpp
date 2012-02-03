#include "WPILib.h"
#include "GamePadL.h"
#include "Components.h"


class RobotDemo : public SimpleRobot
{
	float shooterSpeed;
	const float shooterStep;
	Relay::Value pistonPosition;
	float leftSpeed;
	float rightSpeed;
	float oneStick;
	float sonarVal;
	Components components;
	
public:
	RobotDemo(void):
		shooterSpeed(0),
		shooterStep(0.01),
		pistonPosition(Relay::kOff),
		leftSpeed(0.0),
		rightSpeed(0.0),
		oneStick(0.0),
		sonarVal(0.0)
	{
		components.myRobot.SetExpiration(0.1);
		components.comp.Start();
		components.myRobot.SetSafetyEnabled(true);
	}

void mechanismSet()
{
	components.shooter.Set(shooterSpeed);
	if(oneStick <.03 && oneStick>-.03)
	{
	components.myRobot.TankDrive(leftSpeed, rightSpeed);
	}
	else{
		components.myRobot.TankDrive(oneStick/2, -1*oneStick/2);
	}
	components.piston.Set(pistonPosition);
	cout<<sonarVal<<endl;
	//makes things look neater
}

void stop()
{
	pistonPosition = Relay::kForward;
	leftSpeed = 0.0;
	rightSpeed = 0.0;
	oneStick = 0.0;
	shooterSpeed = 0.0;
}
//DON"T RUN THIS. SERIOUSLY BAD IDEA
void Autonomous(void)
{
	components.myRobot.SetSafetyEnabled(false);
	components.myRobot.Drive(0.5, 0.0); 
	Wait(2.0); //    for 2 seconds
	components.myRobot.Drive(0.0, 0.0);
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

	while (IsOperatorControl())
	{
		//RegulateSpeed(speed);
		//if (leftstick.GetY() == 1 && rightstick.GetY() == 1)
		leftSpeed= components.gamepad1.GetLeftY()*(-1);
		rightSpeed = components.gamepad1.GetRightY();
		oneStick = components.gamepad1.GetDpadY();
		//movement control 
		if (components.gamepad1.GetRawButton(5))
		{
			pistonPosition = Relay::kReverse;
		}
		else{
			pistonPosition = Relay::kForward;
		}
		//fires piston used in the shooter to feed the ball at a constant speed
		if (components.gamepad1.GetRawButton(6))
		{
			shooterSpeed+=shooterStep;    //increaces the shooter speed
		}
		if (components.gamepad1.GetRawButton(8))
		{
			shooterSpeed -=shooterStep;   //lowers the shooter speed
		}
		if (components.gamepad1.GetRawButton(1))
		{
			shooterSpeed=-1;    //turns the shooter on to full
		}
		if (components.gamepad1.GetRawButton(2))
		{
			shooterSpeed=0;     //turns the shooter off
		}
		sonarVal= components.sonar.GetAverageValue();   //sonar?
		mechanismSet();
		Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
