#ifndef __BASEFACTORY_H__
#define __BASEFACTORY_H__
#include "baseprint.h"
#include <iostream>

class BaseFactory {
public:
	/* Constructor */
	BaseFactory();

	/* Pure Virtual Generate Function */
	virtual BasePrint* generatePrint(double value) = 0;
};

#endif