#include "WPILib.h"
#include "AutoStep.h"
#include "CounterCondition.h";
#include "WhileLoopStep.h"

#ifndef FOR_LOOP_STEP_H
#define FOR_LOOP_STEP_H

class ForLoopStep : public WhileLoopStep{
	private:
		AutoStep repeatedStep;
		int numRuns;
	
	public:
		ForLoopStep(AutoStep repeatedStep, int numRuns):
			WhileLoopStep(repeatedStep, CounterCondition.get(numRuns))
		{}
	
};

#endif
