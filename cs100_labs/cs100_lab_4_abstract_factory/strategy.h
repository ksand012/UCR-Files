#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include "container.h"

class Sort {
public:
	/* Constructors */
	Sort();

	/* Pure Virtual Functions */
	virtual void sort(Container* container) = 0;
};

class SelectionSort : public Sort {
public:
	SelectionSort();
	void sort(Container* container);
};

class BubbleSort : public Sort {
public:
	BubbleSort();
	void sort(Container* container);
};

#endif // __STRATEGY_H__
