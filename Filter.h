

#ifndef FILTER_H
#define FILTER_H

const int SIZE = 100;
/*
 * This is a general purpose Rolling Average Filter. It has a blank constructor and a method
 * filter(value a) to filter the newest value.
 */
class Filter{
public:
	float filter(float value);
	Filter();
private:
	float values[SIZE];
	void shiftArray();
};

#endif
