#include "WPILib.h"

#ifndef COLLECTOR_COMPONENTS_H
#define COLLECTOR_COMPONENTS_H

class CollectorComponents{
	
private:
	Relay collectorRotate;
	Relay liftCollector;
	Jaguar convMove;
public:
	CollectorComponents(int spin, int lift, int belt):
		collectorRotate(spin),
		liftCollector(lift),
		convMove(belt)
	{}
	
	void lift(int directionLift){
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
	
	void spin(bool rotateState){
		if(rotateState){
			collectorRotate.Set(Relay::kReverse);
		}
		else{
			collectorRotate.Set(Relay::kOff);
		}
	}
	
	void belt(float speed){
		convMove.SetSpeed(speed);
		}
};

#endif
