#include "AutoManager.h"
#include "AutoStep.h"
#include "WPILib.h"


void AutoManager::start(){
	for(int step = 0; true; step++){
		steps[step].start();
		while(steps[step].isRunning())
		{
			steps[step].run();
		}
		steps[step].stop();
	}
}

void AutoManager::add(AutoStep step){
	steps.push_back(step);
}
