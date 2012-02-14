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
	float shooterRotationSpeed;
	//Camera Variables
	
	//Sonar Variables
	float sonarVal;
	Filter sonarFilter;
	static const int SONAR_OFFSET = 5;
	//Relays
	Relay::Value pistonPosition;
	Relay::Value shifterPosition;
	Relay::Value collectorSpin;
	Relay::Value collectorLift;
	Relay::Value convMove;
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
		shooterRotationSpeed(0),
		sonarVal(0.0),
		pistonPosition(Relay::kForward),
		shifterPosition(Relay::kForward),
		collectorSpin(Relay::kForward),
		collectorLift(Relay::kForward),
		convMove(Relay::kForward)
	{
		//Initialize more complex classes and set expiration while starting the compressor.
		driverStation = DriverStationLCD::GetInstance();
		components.drive.SetExpiration(0.1);
		components.comp.Start();
		components.drive.SetSafetyEnabled(true);
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
	//Set the relays
	components.shooterPiston.Set(pistonPosition);
	components.liftCollector.Set(collectorLift);
	components.convMove.Set(convMove);
	components.collectorRotate.Set(collectorSpin);
	components.superShifters.Set(shifterPosition);
	//Output data to the Driver Station
	std::ostringstream convert;
	convert<<sonarVal;
	string sonarOutput = "Sonar reads: " +  convert.str();
	driverStation->PrintfLine(DriverStationLCD::kUser_Line2, &sonarOutput[0]);
	driverStation->PrintfLine(DriverStationLCD::kUser_Line3, "Test Test");
	std::ostringstream shooterSpeedConversion;
	shooterSpeedConversion<<shooterSpeed;
	string shooterSpeedOutput = "Shooter Speed: " + shooterSpeedConversion.str();
	driverStation->PrintfLine(DriverStationLCD::kUser_Line4, &(shooterSpeedOutput[0]));
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
	components.drive.SetSafetyEnabled(false);
	components.drive.Drive(0.5, 0.0); 
	Wait(20.0); //    for 2 seconds
	components.drive.Drive(0.0, 0.0);
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
		//**********************DRIVER 1 CONTROLS*********************************//
		leftSpeed= components.gamepad1.GetLeftY()*(-1) *speedFactor;
		rightSpeed = components.gamepad1.GetRightY()*(-1) *speedFactor;
		oneStick = components.gamepad1.GetDpadY() *speedFactor;
		if(button3Toggle.isToggleReady(components.gamepad1.GetRawButton(3)))
				{
					if(shifterPosition == Relay::kOff)
					{
						shifterPosition = Relay::kReverse;
					}
					else{
						shifterPosition = Relay::kForward;
					}
				}
		if(components.gamepad1.GetRawButton(5)){
			collectorSpin  = Relay::kReverse;
		}
		else{
			collectorSpin = Relay::kOff;
		}
		if(components.gamepad1.GetRawButton(7)){
					convMove  = Relay::kReverse;
				}
		else{
				convMove = Relay::kOff;
			}
		if(components.gamepad1.GetRawButton(6)){
					collectorLift  = Relay::kReverse;
				}
		else if(components.gamepad1.GetRawButton(8)){
					collectorLift = Relay::kForward;
				}
		else{
			collectorLift = Relay::kOff;
		}
		//**********************DRIVER 2 CONTROLS*********************************//
		if (components.gamepad2.GetRawButton(5))
		{
			pistonPosition = Relay::kReverse;
		}
		else{
			pistonPosition = Relay::kOff;
		}
		//fires piston used in the shooter to feed the ball at a constant speed
		if (components.gamepad2.GetRawButton(6))
		{
			shooterSpeed+= SHOOTER_STEP;    //increaces the shooter speed
		}
		if (components.gamepad2.GetRawButton(8))
		{
			shooterSpeed -= SHOOTER_STEP;   //lowers the shooter speed
		}
		if (components.gamepad2.GetRawButton(1))
		{
			shooterSpeed=1;    //turns the shooter on to full
		}
		if (components.gamepad2.GetRawButton(2))
		{
			shooterSpeed=.50;     //turns the shooter to half
		}
		if(components.gamepad2.GetRawButton(3))
		{
			shooterSpeed = .40;		//sets the shooter to take a shot from the key
		}
		if(components.gamepad2.GetRawButton(4))
		{
			shooterSpeed = 0;		//turns the shooter off
		}
		shooterRotationSpeed = components.gamepad2.GetRawAxis(3);	
		
		sonarVal= sonarFilter.filter(components.sonar.GetValue())/2 + SONAR_OFFSET;  
		mechanismSet();
		Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(RobotDemo);
