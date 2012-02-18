#include "WPILib.h"

#ifndef COUNTER_CONDITION_H
#define COUNTER_CONDITION_H

class CounterCondition{
	private:
		int countTo;
		int value;
	
	public:
		CounterCondition(int countTo){
			this.countTo=countTo;
			value=0;
		}
		
		bool get(){
			return value<countTo;
		}
		
		void reset(){
			value=0;
		}
		
};

#endif
