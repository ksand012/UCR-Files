#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <math.h>
#include "container.h"

class Decorator : public Base {
	protected:
		Base* decorated;
	public:
		virtual double evaluate() = 0;
};

class Ceiling : public Decorator {
	protected:
		Base* decorated;
	public:
		Ceiling();
		Ceiling(Base* x);
		double evaluate();
	
};

class Floor : public Decorator {
	protected:
		Base* decorated;
	public:
		Floor();
		Floor(Base* x); 
		double evaluate();
	
};

class Absolute : public Decorator {
	protected:
		Base* decorated;
	public:
		Absolute();
		Absolute(Base* x);
		double evaluate();
	
};

#endif
