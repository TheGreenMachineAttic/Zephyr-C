#include "ShootStep.h"
#include "Components.h"

 
	ShooterStep::ShooterStep(Components* comp){
		robot = comp;
	}
	void ShooterStep::run(){
		for(int time = 0; time <2000; time++)
		{
		robot->shooter.Set(-1);
		sleep(1);
		}
		for(int time = 0; time <1000; time++)
		{
			robot->piston.Set(Relay::kReverse);
		}
		robot->piston.Set(Relay::kForward);
	}
	void ShooterStep::stop(){
		robot->shooter.Set(0);
		robot->piston.Set(Relay::kForward);
	}
