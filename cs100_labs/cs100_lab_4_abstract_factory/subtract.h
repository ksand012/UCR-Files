#ifndef __SUBTRACT_H__
#define __SUBTRACT_H__
#include "component.h"

class Subtract : public Base {
protected:
	Base * lhs;
	Base* rhs;
public:
	Subtract();
	Subtract(Base* left, Base* right);
	double evaluate();

};

#endif
