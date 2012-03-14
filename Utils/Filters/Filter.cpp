#include "Filter.h"

/*
 * Creates a simple empty filter of size SIZE.
 */
Filter::Filter()
{
	for(int counter = 0; counter<SIZE; counter++)
	{
		values[counter] = 0;
	}
}
/*
 * Shifts the array down by one, so values[0] would become values[1].
 */
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
/*
 * Returns the FIR filtered value.
 */
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
