#ifndef __ADD_H__
#define __ADD_H__
#include "component.h"

class Add : public Base {
protected:
	Base * lhs;
	Base* rhs;
public:
	Add();
	Add(Base* left, Base* right);
	double evaluate();

};

#endif
