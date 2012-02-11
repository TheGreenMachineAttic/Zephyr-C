#include "WPILib.h"

#ifndef SHOOTER_COMPONENTS_H
#define SHOOTER_COMPONENTS_H

class ShooterComponents{

private:
Jaguar shooterLeft;
Jaguar shooterRight;
Jaguar shooterRotator;
Relay shooterPiston;

public:
	ShooterComponents(int left, int right, int rotator, int piston):
		shooterLeft(left),
		shooterRight(right),
		shooterRotator(rotator),
		shooterPiston(piston)
		{}
	
	void setShooterSpeed(float left, float right){
		 shooterLeft.SetSpeed(left);
		 shooterRight.SetSpeed(right);
	}
	
	void setRotate(float rotator){
		shooterRotator.SetSpeed(rotator);
	}
	
	void piston(bool position){
		if(position){
			shooterPiston.Set(Relay::kReverse);
		}
		else{
			shooterPiston.Set(Relay::kForward);
		}
	}

};

#endif
