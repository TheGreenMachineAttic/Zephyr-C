#include "WPILib.h"
#include "..\Utils\Filter.h"

#ifndef SONAR_COMPONENTS_H
#define SONAR_COMPONENTS_H

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
		double getFilteredValue(){
			return sonarFilter.filter(sonar.GetValue())/2+CONSTANT_SONAR;
		}
		/*
		 * Returns the raw unfiltered value.
		 */
		double getRawValue(int value){
			return sonar.GetValue()/2+CONSTANT_SONAR;
		}
		
		/*
		 * Returns the recommended power as decided by our manually calibrated distance to power curve.
		 */
		double getPower(){
			return 0.0;
		}

		
};

#endif
