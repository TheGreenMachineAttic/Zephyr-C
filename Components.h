#include "GamePadL.h"
#include "WPILib.h"

#ifndef COMPONENTS_H
#define COMPONENTS_H

class Components{
private:
	static const int leftMotors = 2;
	static const int rightMotors = 1;
	static const int gamepad1Input = 1;
	static const int gamepad2Input = 2;
	static const int compInput = 1;
	static const int compSpike = 1;
	static const int shooterJaguar = 3;
	static const int sonarInput = 1;
	static const int pistonInput = 2;
public:
		RobotDrive myRobot;
		GamepadL gamepad1; 
		GamepadL gamepad2;
		Jaguar shooter;
		Compressor comp;
		Relay piston;
		DriverStation *driveStation;
		AnalogChannel sonar;

		Components():
			myRobot(leftMotors,rightMotors),
			gamepad1(gamepad1Input),
			gamepad2(gamepad2Input),
			comp(compInput,compSpike),
			shooter(shooterJaguar),
			piston(pistonInput),
			sonar(sonarInput)
			{}

			
};

#endif
