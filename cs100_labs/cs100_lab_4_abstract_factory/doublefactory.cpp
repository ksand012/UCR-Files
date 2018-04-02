#include "doublefactory.h"
#include "doubleprint.h"

DoubleFactory::DoubleFactory() {
}


BasePrint*  DoubleFactory::generatePrint(double value) {
	BasePrint* Cosmo = new DoublePrint(value);
	return Cosmo;
};