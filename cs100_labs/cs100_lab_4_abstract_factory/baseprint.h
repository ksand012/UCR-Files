#ifndef __BASEPRINT_H__
#define __BASEPRINT_H__

class BasePrint {
protected:
	/* Value to Print */
	double value;

public:
	/* Constructors */
	BasePrint();
	BasePrint(double value);

	/* Pure Virtual Print Function */
	virtual void print() = 0;
};
#endif