#ifndef __DIVIDE_H__
#define __DIVIDE_H__
#include "component.h"

class Divide : public Base {
protected:
	Base* lhs;
	Base* rhs;
public:
	Divide();
	Divide(Base* left, Base* right);
	double evaluate();

};

#endif
