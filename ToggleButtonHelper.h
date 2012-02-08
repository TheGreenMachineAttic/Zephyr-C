#ifndef TOGGLE_HELPER
#define TOGGLE_HELPER

/*
 * ToggleHelper is a class designed to support a true toggle button, ie hit once to turn on and once
 * to turn off.
 */
class ToggleHelper{
public:
	ToggleHelper()
	{
		toggleReady = false;
	}
	bool isToggleReady(bool latestState)
	{
		if(!latestState){
		            toggleReady = true;
		        }

		        else if(latestState && toggleReady){

		            toggleReady = false;
		            return true;
		        }
		        else{
		            toggleReady = false;
		        }
		        return false;
	}
private:
	bool toggleReady;
};

#endif
