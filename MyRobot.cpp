#include "WPILib.h"
#include "GamePadL.h"
#include "Components.h"
#include "ToggleButtonHelper.h"
#include "Filter.h"
#include <sstream>

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
	const float SHOOTER_STEP;
		
	//Camera Variables
	
	//Sonar Variables
	float sonarVal;
	Filter sonarFilter;
	static const int SONAR_OFFSET = 5;
	//Shooter Piston Variables
	Relay::Value pistonPosition;
	
	//Components
	Components components;
	
	//Driver Station
	DriverStationLCD *driverStation;
public:
	RobotDemo(void):
		leftSpeed(0.0),
		rightSpeed(0.0),
		oneStick(0.0),
		speedFactor(1.0),
		shooterSpeed(0),
		SHOOTER_STEP(0.01),
		sonarVal(0.0),
		pistonPosition(Relay::kOff)
	{
		//Initialize more complex classes and set expiration while starting the compressor.
		driverStation = DriverStationLCD::GetInstance();
		components.myRobot.SetExpiration(0.1);
		components.comp.Start();
		components.myRobot.SetSafetyEnabled(true);
	}
/*
 * Set the motors and relays to the appropriate settings.
 */
void mechanismSet() 
{
	//Set the shooter
	components.shooterLeft.Set(shooterSpeed);
	components.shooterRight.Set(shooterSpeed);
	
	//Driving Logic for One Stick Drive
	if(oneStick == 0)
	{
	components.myRobot.TankDrive(leftSpeed*speedFactor, rightSpeed*speedFactor);
	}
	else{
		components.myRobot.TankDrive(oneStick * speedFactor, speedFactor*oneStick);
	}
	components.shooterPiston.Set(pistonPosition);
	
	//Output data to the Driver Station
	std::ostringstream convert;
	convert<<sonarVal;
	string sonarOutput = "Sonar reads: " +  convert.str();
	driverStation->PrintfLine(DriverStationLCD::kUser_Line2, &sonarOutput[0]);
	driverStation->PrintfLine(DriverStationLCD::kUser_Line3, "Test Test");
	std::ostringstream speedFactorConversion;
	speedFactorConversion<<speedFactor;
	string speedFactorOutput = "Speed Factor: " + speedFactorConversion.str();
	driverStation->PrintfLine(DriverStationLCD::kUser_Line4, &(speedFactorOutput[0]));
	driverStation->UpdateLCD();
	
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
	Wait(20.0); //    for 2 seconds
	components.myRobot.Drive(0.0, 0.0);
}

/*
 * Used to check whether the speed is in expected range
 */
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

/*
 * Collect data and update the various speed and relay values
 */
void OperatorControl(void)
{

	while (IsOperatorControl())
	{
		leftSpeed= components.gamepad1.GetLeftY()*(-1) *speedFactor;
		rightSpeed = components.gamepad1.GetRightY() *speedFactor;
		oneStick = components.gamepad1.GetDpadY() *speedFactor;
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
			shooterSpeed+= SHOOTER_STEP;    //increaces the shooter speed
		}
		if (components.gamepad1.GetRawButton(8))
		{
			shooterSpeed -= SHOOTER_STEP;   //lowers the shooter speed
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
			else if(speedFactor == .5){
				speedFactor = 1;
			}
		}
		sonarVal= sonarFilter.filter(components.sonar.GetValue())/2 + SONAR_OFFSET;  
		//sonarVal = components.sonar.GetValue()/2;//sonar
		mechanismSet();
		Wait(0.005);		//i failed at pushing
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
