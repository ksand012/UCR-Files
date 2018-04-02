#ifndef __OP_H__
#define __OP_H__
#include "component.h"

class Op : public Base {
protected:
	double value;
public:
	Op();
	Op(double x);
	double evaluate();

};

#endif
