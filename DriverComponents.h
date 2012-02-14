#include "WPILib.h"

#ifndef DRIVE_COMPONENTS_H
#define DRIVE_COMPONENTS_H

class DrivingComponents{
private:
	RobotDrive myRobot;
	Relay  superShifters;
public:

	DrivingComponents(int left, int right, int shift):
		myRobot(left, right),
		superShifters(shift)
		{}
	void setDrivingSpeed(float leftSpeed, float rightSpeed){
		myRobot.TankDrive(leftSpeed, rightSpeed);
	}
	void shift(bool state){
		if(state){
			superShifters.Set(Relay::kForward);
		}
		else{
			superShifters.Set(Relay::kReverse);
		}
	}
	void SetExpiration(float ex){
		myRobot.SetExpiration(ex);
	}
	void SetSafetyEnabled(bool er){
		myRobot.SetSafetyEnabled(er);
	}
};

#endif
