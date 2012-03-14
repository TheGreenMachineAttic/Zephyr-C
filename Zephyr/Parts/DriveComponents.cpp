#include "DriveComponents.h"

void DriveComponents::setDrivingSpeed(float leftSpeed, float rightSpeed){
		myRobot.TankDrive(leftSpeed, rightSpeed);
}

void DriveComponents::shift(bool state){
		if(state){
			superShifters.Set(Relay::kForward);
		}
		else{
			superShifters.Set(Relay::kReverse);
		}
}

void DriveComponents::setExpiration(float ex){
		myRobot.SetExpiration(ex);
}

void DriveComponents::setSafetyEnabled(bool en){
		myRobot.SetSafetyEnabled(en);
}
