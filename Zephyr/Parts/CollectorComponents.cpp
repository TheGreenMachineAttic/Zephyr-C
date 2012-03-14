#include "CollectorComponents.h"
#include "WPILib.h"

void CollectorComponents::lift(int directionLift){
		switch(directionLift){
					case 1:
						liftCollector.Set(Relay::kForward);
						break;
					case 2:
						liftCollector.Set(Relay::kReverse);
						break;
					default:
						liftCollector.Set(Relay::kOff);
						break;
		}
}

void CollectorComponents::spin(bool rotateState){
		if(rotateState){
			collectorRotate.Set(Relay::kReverse);
		}
		else{
			collectorRotate.Set(Relay::kOff);
		}
}

void CollectorComponents::belt(float speed){
	convMove.SetSpeed(speed);
}
