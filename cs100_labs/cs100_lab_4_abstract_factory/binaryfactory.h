#ifndef __BINARYFACTORY_H__
#define __BINARYFACTORY_H__
#include "basefactory.h"

class BinaryFactory : public BaseFactory {
protected:
public:
	BinaryFactory();
	BasePrint* generatePrint(double value);
};

#endif