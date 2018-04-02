#ifndef __MULTIPLY_H__
#define __MULTIPLY_H__
#include "component.h"

class Multiply
{
protected:
	Base* lhs;
	Base* rhs;
public:
	Multiply();
	Multiply(Base* left, Base* right);
	double evaluate();

};

#endif
