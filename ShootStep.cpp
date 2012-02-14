#include "ShootStep.h"
#include "Components.h"

 
	ShooterStep::ShooterStep(Components* comp){
		robot = comp;
	}
	void ShooterStep::run(){
		for(int time = 0; time <2000; time++)
		{
		robot->shooter.setShooterSpeed(-1);
		sleep(1);
		}
		for(int time = 0; time <1000; time++)
		{
			robot->shooter.piston(true);
		}
		robot->shooter.piston(false);
	}
	void ShooterStep::stop(){
		robot->shooter.setShooterSpeed(0);
		robot->shooter.piston(false);
	}
