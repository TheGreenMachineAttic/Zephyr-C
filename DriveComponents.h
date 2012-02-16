#include "WPILib.h"

#ifndef DRIVE_COMPONENTS_H
#define DRIVE_COMPONENTS_H

class DrivingComponents{
private:
	RobotDrive myRobot;
	Relay  superShifters;
public:
	/*
	 * Constructs a DrivingComponents objects, intializes RobotDrive with ints left and right and
	 * Relay superShifters with int shift.
	 */
	DrivingComponents(int left, int right, int shift):
		myRobot(left, right),
		superShifters(shift)
		{}
	/*
	 * Sets myRobot to tank drive using float leftSpeed for the left motor speed.
	 * And float rightSpeed for the right motor speed.
	 */
	void setDrivingSpeed(float leftSpeed, float rightSpeed){
		myRobot.TankDrive(leftSpeed, rightSpeed);
	}
	/*
	 * Shifts the supershifter to up if state is true,
	 * and down if false.
	 */
	void shift(bool state){
		if(state){
			superShifters.Set(Relay::kForward);
		}
		else{
			superShifters.Set(Relay::kReverse);
		}
	}
	/*
	 * Sets my robots expiration with float ex.
	 */
	void SetExpiration(float ex){
		myRobot.SetExpiration(ex);
	}
	/*
	 * Sets saftey enabled on if bool er is true, otherwise it is set to false.
	 */
	void SetSafetyEnabled(bool er){
		myRobot.SetSafetyEnabled(er);
	}
};

#endif
