#ifndef FILTER_H
#define FILTER_H

class Filter{
public:
	static Filter getInstance(int size);
	float filter(float value);
private:
	float values[];
	Filter(float tap[]);
	void shiftArray();
};

#endif
