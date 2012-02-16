#ifndef TOGGLE_HELPER
#define TOGGLE_HELPER

/*
 * ToggleHelper is a class designed to support a true toggle button, ie hit once to turn on and once
 * to turn off.
 */
class ToggleHelper{
public:
	/*
	 * Constructs ToggleHelper with toggleReady equal to false.
	 */
	ToggleHelper()
	{
		toggleReady = false;
	}
	/*
	 * Returns true if the latests state is both true and different from toggle ready.
	 */
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
