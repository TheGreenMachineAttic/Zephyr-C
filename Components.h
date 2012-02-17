

#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "GamePadL.h"
#include "WPILib.h"
#include "DriveComponents.h"
#include "ShooterComponents.h"
#include "CollectorComponents.h"
#include "SonarComponents.h"
/*
 * This contains the complete list of all components attached to the robot or driver station.
 */
class Components{
private:
	//JAGUARS
	static const int RIGHT_MOTOR = 1;
	static const int LEFT_MOTOR = 2;
	static const int SHOOTER_JAGUAR_LEFT  = 3;
	static const int SHOOTER_JAGUAR_RIGHT = 4; 
	static const int SHOOTER_ROTATION = 5;
	static const int CONV_MOV = 6;
	
	//GAMEPADS
	static const int GAMEPAD_INPUT_1 = 1;
	static const int GAMEPAD_INPUT_2 = 2;
	//RELAYS
	static const int COMP_INPUT = 1;
	static const int PISTON_INPUT = 2;
	static const int SUPER_SHIFTER = 3;
	static const int BALL_COLL_ROTAT = 4;
	static const int BALL_COLL_LIFT = 5;
	//DIGITAL INPUT
	static const int COMP_DIGITAL_INPUT = 1;
	//SERVOS
	static const int CAMERA_SERVO = 7;
	//ANALOG INPUTS
	static const int SONAR_INPUT = 1;

	
	
public:
		//WRAPPER CLASSES
		DrivingComponents drive;
		ShooterComponents shooter;
		CollectorComponents collector;
		SonarComponents sonar;
		//GAMEPADS
		GamepadL gamepad1; 
		GamepadL gamepad2;
		//SERVO
		Servo cameraServo;
		//COMPRESSOR
		Compressor comp;

		Components():
			drive(LEFT_MOTOR, RIGHT_MOTOR, SUPER_SHIFTER),
			shooter(SHOOTER_JAGUAR_LEFT, SHOOTER_JAGUAR_RIGHT, SHOOTER_ROTATION, PISTON_INPUT),
			collector(BALL_COLL_ROTAT,BALL_COLL_LIFT,CONV_MOV),
			sonar(SONAR_INPUT),
			gamepad1(GAMEPAD_INPUT_1),
			gamepad2(GAMEPAD_INPUT_2),
			cameraServo(CAMERA_SERVO),
			comp(COMP_DIGITAL_INPUT, COMP_INPUT)
			
			{}

			
};

#endif
