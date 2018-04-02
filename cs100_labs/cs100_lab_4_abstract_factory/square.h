#ifndef __SQUARE_H__
#define __SQUARE_H__
#include "component.h"

class Square : public Base {
protected:
	Base * expression;
public:
	Square();
	Square(Base* x);
	double evaluate();

};

#endif
