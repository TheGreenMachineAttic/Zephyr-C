#include "ShooterComponents.h"

void ShooterComponents::setShooterSpeed(float speed){
		 shooterLeft.SetSpeed(speed);
		 shooterRight.SetSpeed(-speed);
}

void ShooterComponents::setRotate(float rotator){
		shooterRotator.SetSpeed(rotator);
}

void ShooterComponents::piston(bool position){
		if(position){
			shooterPiston.Set(Relay::kReverse);
		}
		else{
			shooterPiston.Set(Relay::kForward);
		}
}
