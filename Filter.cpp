#include "Filter.h"


Filter::Filter()
{
	for(int counter = 0; counter<SIZE; counter++)
	{
		values[counter] = 0;
	}
}

void Filter::shiftArray()
{
	float tempArray[SIZE];
	for(int counter = 0; counter<SIZE; counter++)
		{
			tempArray[counter] = values[counter];
		}
	for(int counter = 0; counter<SIZE; counter++)
		{
			values[counter] = tempArray[counter-1];
		}
}

float Filter::filter(float value)
{
	shiftArray();
	values[0] = value;
	float total = 0.0;
	for(int counter = 0; counter<SIZE; counter++)
	{
		total+=values[counter];
	}
	return (total/SIZE);
}
