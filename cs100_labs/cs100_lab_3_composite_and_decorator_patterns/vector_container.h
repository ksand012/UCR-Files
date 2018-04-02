#ifndef __VECTOR_CONTAINER_H__
#define __VECTOR_CONTAINER_H__

#include <vector>
#include "strategy.h"
#include "container.h"

class VectorContainer : public Container {
	private:
		std::vector<Base*> baseVector;
	public:
		VectorContainer();
		VectorContainer(Sort* function) : Container(function) {}
		void set_sort_function(Sort* sort_function);
		void sort();
		void add_element(Base* element);
		void print();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};

#endif
