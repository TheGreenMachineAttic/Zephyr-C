#include "WPILib.h"
#include "GamePadL.h"
#include "Components.h"
#include "ToggleButtonHelper.h"


class RobotDemo : public SimpleRobot
{
	//Driving Variables
	float leftSpeed;
	float rightSpeed;
	float oneStick;
	
	//Slow Speed Variables
	ToggleHelper button3Toggle;
	float speedFactor;
	
	//Shooter Speed
	float shooterSpeed;
	const float shooterStep;
	
	//Filters Variables
	
	//Camera Variables
	
	//Sonar Variables
	float sonarVal;
	
	//Shooter Piston Variables
	Relay::Value pistonPosition;
	
	Components components;
	
public:
	RobotDemo(void):
		leftSpeed(0.0),
		rightSpeed(0.0),
		oneStick(0.0),
		speedFactor(1.0),
		shooterSpeed(0),
		shooterStep(0.01),
		sonarVal(0.0),
		pistonPosition(Relay::kOff)
	{
		components.myRobot.SetExpiration(0.1);
		components.comp.Start();
		components.myRobot.SetSafetyEnabled(true);
	}

void mechanismSet() //makes things look neater
{
	components.shooter.Set(shooterSpeed);
	
	if(oneStick == 0)
	{
	components.myRobot.TankDrive(leftSpeed * speedFactor, rightSpeed * speedFactor);
	}
	else{
		components.myRobot.TankDrive((oneStick * speedFactor)/2, -1*((speedFactor*oneStick)/2));
	}
	components.piston.Set(pistonPosition);
	
	
}

//Stop all motors
void stop()
{
	pistonPosition = Relay::kForward;
	leftSpeed = 0.0;
	rightSpeed = 0.0;
	oneStick = 0.0;
	shooterSpeed = 0.0;
	mechanismSet();
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
		if(button3Toggle.isToggleReady(components.gamepad1.GetRawButton(3)))
		{
			if(speedFactor == 1)
			{
				speedFactor = .5;
			}
			if(speedFactor == .5){
				speedFactor = 1;
			}
		}
		sonarVal= components.sonar.GetValue();   //sonar
		mechanismSet();
		Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
