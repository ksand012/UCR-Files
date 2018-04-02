#include "vector_container.h"
#include <iostream>


VectorContainer::VectorContainer() : Container() {}

void VectorContainer::set_sort_function(Sort* sort_function) {
	this->sort_function = sort_function;
}

void VectorContainer::sort() {
	this->sort_function->sort(this);
}

void VectorContainer::add_element(Base* element) {
	baseVector.push_back(element);
}

void VectorContainer::print() {
	for(unsigned int i = 0; i < baseVector.size(); ++i) {
		cout << baseVector.at(i)->evaluate() << endl;
	}
	cout << endl;
}

void VectorContainer::swap(int i, int j) {
	Base* temp = baseVector.at(i);
	baseVector.at(i) = baseVector.at(j);
	baseVector.at(j) = temp;
	temp = 0;
}

Base* VectorContainer::at(int i) {
	return baseVector.at(i);
}

int VectorContainer::size() {
	return baseVector.size();
}
