#include "WPILib.h"
#include "Filter.h"

#ifndef SONAR_COMPONENTS_H
#define SONAR_COMPONENTS_H

class SonarComponents{
	
	private:
	AnalogChannel sonar;
	Filter sonarFilter;
	static const int CONSTANT_SONAR=5;
	static const double LAUNCH_ANGLE=52.0;

	public:
		SonarComponents(int channel):
			sonar(channel)
			{}
	
		double getFilteredValue(){
			return sonarFilter.filter(sonar.GetValue())/2+CONSTANT_SONAR;
		}

		double getRawValue(int value){
			return sonar.GetValue()/2+CONSTANT_SONAR;
		}
		
		double getPower(){
			return 0.0;
		}

		
};

#endif
