#ifndef AUTO_MANAGER_H
#define AUTO_MANAGER_H

#include "AutoStep.h"
using namespace std;
class AutoManager{
public:
	void start();
	AutoManager();
private:
	vector<AutoStep> steps;
};

#endif
