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
	
	void lift(int directionLift);
	
	void spin(bool rotateState);
	
	void belt(float speed);
};

#endif
