#ifndef __BINARYPRINT_H__
#define __BINARYPRINT_H__
#include "baseprint.h"

class BinaryPrint : public BasePrint {
protected:
	double value;
public:
	BinaryPrint();
	BinaryPrint(double value);
	void print();

};

#endif