#ifndef __HEXFACTORY_H__
#define __HEXFACTORY_H__
#include "basefactory.h"

class HexFactory : public BaseFactory {
protected:
public:
	HexFactory();
	BasePrint* generatePrint(double value);
};

#endif