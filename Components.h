#include "GamePadL.h"
#include "WPILib.h"

#ifndef COMPONENTS_H
#define COMPONENTS_H

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
	//GAMEPADS
	static const int GAMEPAD_INPUT_1 = 1;
	static const int GAMEPAD_INPUT_2 = 2;
	//RELAYS
	static const int COMP_INPUT = 1;
	static const int PISTON_INPUT = 2;
	static const int SUPER_SHIFTERS = 3;
	static const int BALL_COLL_ROTAT = 4;
	static const int BALL_COLL_LIFT = 5;
	static const int CONV_MOV = 6;
	//ANALOG INPUTS
	static const int SONAR_INPUT = 1;
	//DIGITAL INPUT
	static const int COMP_DIGITAL_INPUT = 1;
	//SERVOS
	static const int CAMERA_SERVO = 7;
public:
		//ROBOT
		RobotDrive myRobot;
		//GAMEPADS
		GamepadL gamepad1; 
		GamepadL gamepad2;
		//JAGUARS
		Jaguar shooterRight;
		Jaguar shooterLeft;
		Jaguar shooterRotator;
		//COMPRESSOR
		Compressor comp;
		//RELAYS
		Relay shooterPiston;
		Relay superShifters;
		Relay collectorRotate;
		Relay liftCollector;
		Relay convMove;
		//ANALOG INPUTS
		AnalogChannel sonar;
		//SERVOS
		Servo cameraServo;
		Components():
			myRobot(LEFT_MOTOR, RIGHT_MOTOR),
			gamepad1(GAMEPAD_INPUT_1),
			gamepad2(GAMEPAD_INPUT_2),
			shooterRight(SHOOTER_JAGUAR_RIGHT),
			shooterLeft(SHOOTER_JAGUAR_LEFT),
			shooterRotator(SHOOTER_ROTATION),
			comp(COMP_DIGITAL_INPUT,COMP_INPUT),
			shooterPiston(PISTON_INPUT),
			superShifters(SUPER_SHIFTERS),
			collectorRotate(BALL_COLL_ROTAT),
			liftCollector(BALL_COLL_LIFT),
			convMove(CONV_MOV),
			sonar(SONAR_INPUT),
			cameraServo(CAMERA_SERVO)
			{}

			
};

#endif
