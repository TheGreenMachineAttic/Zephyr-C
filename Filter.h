

#ifndef FILTER_H
#define FILTER_H

const int SIZE = 100;

class Filter{
public:
	float filter(float value);
	Filter();
private:
	float values[SIZE];
	void shiftArray();
};

#endif
