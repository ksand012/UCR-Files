#include "binaryfactory.h"
#include "binaryprint.h"

BinaryFactory::BinaryFactory() {
}

BasePrint*  BinaryFactory::generatePrint(double value) {
	BasePrint* Kramer = new BinaryPrint(value);
	return Kramer;
};