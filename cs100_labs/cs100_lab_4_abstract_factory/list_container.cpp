#include "list_container.h"
#include "doublefactory.h"
#include "hexfactory.h"
#include "binaryfactory.h"
#include <iostream>

ListContainer::ListContainer() : Container() {
}

ListContainer::ListContainer(BaseFactory* fact) {
	factory = fact;
}

void ListContainer::set_sort_function(Sort* sort_function) {
	this->sort_function = sort_function;
}

void ListContainer::sort() {
	this->sort_function->sort(this);
}

void ListContainer::add_element(Base* element) {
	baseList.push_back(element);
}

void ListContainer::print() {
	for (std::list<Base*>::iterator it = baseList.begin(); it != baseList.end(); ++it) {
		double printable = ((*it)->evaluate());
		factory->generatePrint(printable)->print();
	}
}

void ListContainer::swap(int i, int j) {
	int counter = 0;
	int counter_2 = 0;
	Base* temp_1 = NULL;
	Base* temp_2 = NULL;
	for( std::list<Base*>::iterator it = baseList.begin(); it != baseList.end(); ++it ) {
		if( counter == i ) {
			temp_1 = *it;
		}
		if( counter == j ) {
			temp_2 = *it;
		}
		++counter;
	}
	counter = 0;
	for( std::list<Base*>::iterator it = baseList.begin(); it != baseList.end(); ++it ) {
		if( counter == i ) {
			*it = temp_2;
		}
		if( counter == j ) {
			*it = temp_1;
		}
		++counter;
	}
}

Base* ListContainer::at(int i) {
	std::list<Base*>::iterator it;
	int counter = 0;
	for( it = baseList.begin(); it != baseList.end(); ++it ) {
		if( counter == i ) {
			return *it;
		}
	++counter;
	}
	return *it;
}

int ListContainer::size() {
	return baseList.size();
}