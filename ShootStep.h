#ifndef SHOOT_STEP_H
#define SHOOT_STEP_H
#include "AutoStep.h"
#include "Components.h"

class ShooterStep:AutoStep{
public:
	void run();
	bool isRunning(){return false;};
	void stop();
	ShooterStep(Components* comp);
private:
	Components *robot;
	virtual ~ShooterStep(){delete robot;};
};

#endif
