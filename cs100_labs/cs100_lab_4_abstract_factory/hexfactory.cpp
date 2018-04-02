#include "hexfactory.h"
#include "hexprint.h"

HexFactory::HexFactory() {
}

BasePrint* HexFactory::generatePrint(double value) {
	BasePrint* Seinfeld = new HexPrint(value);
	return Seinfeld;
};