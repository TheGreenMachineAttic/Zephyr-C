#ifndef AUTO_STEP_H
#define AUTO_STEP_H

class AutoStep{
public:
	virtual void start(){}
	virtual void run(){}
	virtual bool isRunning(){return false;}
	virtual void stop(){}
};

#endif
