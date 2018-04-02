#ifndef __HEXPRINT_H__
#define __HEXPRINT_H__
#include "baseprint.h"

class HexPrint : public BasePrint {
protected:
	double value;
public:
	HexPrint();
	HexPrint(double value);
	void print();

};

#endif