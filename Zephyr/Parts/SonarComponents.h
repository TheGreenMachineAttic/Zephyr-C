
#ifndef SONAR_COMPONENTS_H
#define SONAR_COMPONENTS_H

#include "WPILib.h"
#include "..\Zephyr-C\Utils\Filters\Filter.h"

class SonarComponents{
	
	private:
	AnalogChannel sonar;
	Filter sonarFilter;
	static const int CONSTANT_SONAR=5;
	static const double LAUNCH_ANGLE=52.0;

	public:
		/*
		 * Creates an analog channel on channel int channel.
		 */
		SonarComponents(int channel):
			sonar(channel)
			{}
	
		/*
		 * Returns the newest value viltered by the FIR Filter.
		 */
		double getFilteredValue();
		/*
		 * Returns the raw unfiltered value.
		 */
		double getRawValue(int value);
		
		/*
		 * Returns the recommended power as decided by our manually calibrated distance to power curve.
		 */
		double getPower(){
			return 0.0;
		}

		
};

#endif
