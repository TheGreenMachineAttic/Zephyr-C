#include "SonarComponents.h"

double SonarComponents::getFilteredValue(){
			return sonarFilter.filter(sonar.GetValue())/2+CONSTANT_SONAR;
}

double SonarComponents::getRawValue(int value){
			return sonar.GetValue()/2+CONSTANT_SONAR;
}
