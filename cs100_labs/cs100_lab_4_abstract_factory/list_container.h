#ifndef __LIST_CONTAINER_H__
#define __LIST_CONTAINER_H__

#include <list>
#include <iterator>
#include "container.h"
#include "strategy.h"

class ListContainer : public Container {
    private:
	std::list<Base*> baseList;

    public:
	ListContainer();
	void set_sort_function(Sort* sort_function);
	void sort();
	void add_element(Base* element);
	void print();
	void swap(int i, int j);
	Base* at(int i);
	int size();
	ListContainer(BaseFactory* fact);
};

#endif
