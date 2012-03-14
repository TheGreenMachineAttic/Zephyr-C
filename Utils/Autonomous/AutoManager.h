#ifndef AUTO_MANAGER_H
#define AUTO_MANAGER_H
#include <vector>
#include "AutoStep.h"
using namespace std;

class AutoManager{
public:
	AutoStep getNextStep();
	void add(AutoStep step);
	AutoManager(){
		numberOfSteps = 0;
		currentStep = -1;
		}
private:
	vector<AutoStep> steps;
	int numberOfSteps;
	int currentStep;
};

#endif
