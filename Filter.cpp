#include "Filter.h"

Filter Filter::getInstance(int size)
{
	float tempValues[size];
	for(int counter = 0; counter<size; counter++)
	{
		tempValues[counter] = 0;
	}
	return Filter(tempValues);
}

Filter::Filter(float tempValues[])
{
	for(int counter = 0; counter<sizeof(tempValues)/sizeof(float); counter++)
	{
		values[counter] = tempValues[counter];
	}
}

void Filter::shiftArray()
{
	float tempArray[sizeof(values)/sizeof(float)];
	for(int counter = 1; counter<sizeof(values)/sizeof(float); counter++)
	{
		tempArray[counter] = values[counter-1];
	}
	for(int counter = 0; counter<sizeof(values)/sizeof(values); counter++)
		{
			values[counter] = tempArray[counter];
		}
}

float Filter::filter(float value)
{
	shiftArray();
	values[0] = value;
	float total = 0.0;
	for(int counter = 0; counter<sizeof(values)/sizeof(float); counter++)
	{
		total+=values[counter]/(sizeof(values)/sizeof(float));
	}
	return total;
}
