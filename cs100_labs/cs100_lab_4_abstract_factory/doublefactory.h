#ifndef __DOUBLEFACTORY_H__
#define __DOUBLEFACTORY_H__
#include "basefactory.h"

class DoubleFactory : public BaseFactory {
protected:
public:
	DoubleFactory();
	BasePrint* generatePrint(double value);
};

#endif