#include "AutoManager.h"
#include "AutoStep.h"
#include "WPILib.h"


AutoStep AutoManager::getNextStep(){
	currentStep++;
	return steps[currentStep];
}

void AutoManager::add(AutoStep step){
	steps.push_back(step);
	numberOfSteps++;
}
