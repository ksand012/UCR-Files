#ifndef __DOUBLEPRINT_H__
#define __DOUBLEPRINT_H__
#include "baseprint.h"

class DoublePrint : public BasePrint {
protected:
	double value;
public:
	DoublePrint();
	DoublePrint(double value);
	void print();

};

#endif