#ifndef AUTO_MANAGER_H
#define AUTO_MANAGER_H
#include <vector>
#include "AutoStep.h"
using namespace std;
class AutoManager{
public:
	void start();
	void add(AutoStep step);
private:
	vector<AutoStep> steps;
};

#endif
