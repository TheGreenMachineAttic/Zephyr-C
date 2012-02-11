

#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "GamePadL.h"
#include "WPILib.h"
#include "DriveComponents.h"
/*
 * This contains the complete list of all components attached to the robot or driver station.
 */
class Components{
private:
	//JAGUARS
	static int const  RIGHT_MOTOR = 1;
	static int const  LEFT_MOTOR = 2;
	static const int SHOOTER_JAGUAR_LEFT  = 3;
	static const int SHOOTER_JAGUAR_RIGHT = 4; 
	static const int SHOOTER_ROTATION = 5;
	//GAMEPADS
	static const int GAMEPAD_INPUT_1 = 1;
	static const int GAMEPAD_INPUT_2 = 2;
	//RELAYS
	static const int COMP_INPUT = 1;
	static const int PISTON_INPUT = 2;
	static int const  SUPER_SHIFTER = 3;
	static const int BALL_COLL_ROTAT = 4;
	static const int BALL_COLL_LIFT = 5;
	static const int CONV_MOV = 6;
	//ANALOG INPUTS
	static const int SONAR_INPUT = 1;
	//DIGITAL INPUT
	static const int COMP_DIGITAL_INPUT = 1;
public:
		//Wrapper Classes
		DrivingComponents drive;
		//GAMEPADS
		GamepadL gamepad1; 
		GamepadL gamepad2;
		//COMPRESSOR
		Compressor comp;
		//RELAYS
		Relay collectorRotate;
		Relay liftCollector;
		Relay convMove;
		//ANALOG INPUTS
		AnalogChannel sonar;
		Components():
			drive(LEFT_MOTOR, RIGHT_MOTOR, SUPER_SHIFTER),
			gamepad1(GAMEPAD_INPUT_1),
			gamepad2(GAMEPAD_INPUT_2),
			comp(COMP_DIGITAL_INPUT,COMP_INPUT),
			collectorRotate(BALL_COLL_ROTAT),
			liftCollector(BALL_COLL_LIFT),
			convMove(CONV_MOV),
			sonar(SONAR_INPUT)
			{}

			
};

#endif
