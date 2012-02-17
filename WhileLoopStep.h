#include "WPILib.h"
#include "AutoStep.h"
#include "LoopCondition.h"

class WhileLoopStep{

	private:
		AutoStep repeatedStep;
		LoopCondition loopCondition;
		
	public:
		WhileLoopStep(AutoStep repeatedStep, LoopCondition loopCondition){
			this.repeatedStep=repeatedStep;
			this.loopCondition=loopCondition;
		}
		
		void start(){
			repeatedStep.start();
		}
		
		void run(){
			if(repeatedStep.isRunning()){
				repeatedStep.run();
			} else if(isRunning()){
				repeatedStep.stop();
				repeatedStep.start();
			}
		}
		
		void stop(){
			repeatedStep.stop();
			loopCondition.reset();
		}
		
		void isRunning(){
			return loopCondition.get();
		}
};
