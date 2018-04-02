#include "strategy.h"
#include <iostream>

Sort::Sort() {}

SelectionSort::SelectionSort() : Sort() {}

void SelectionSort::sort(Container* container) { 
	int i = 0;
	int j = 0;
	int min_index = 0;
	int n = container->size();
	
	for( i = 0; i < n - 1; ++i ) {
		min_index = i;
		for( j = i + 1; j < n; ++j ) {
			if(container->at(j)->evaluate() < container->at(min_index)->evaluate())
				min_index = j;
			container->swap(min_index, i);
		}
	}
}

BubbleSort::BubbleSort() : Sort() {}

void BubbleSort::sort(Container* container) { // logic is if I wanted to sort the elements in the vector in ascending order and if the first element is greater than the second, then I will swap the elements, but if the first element is smaller than the second, then I won't swap the element, and so on for the second, third ... third, fourth .... fourth, n'th
	int i = 0; //iteration i
	int j = 0; //iteration j
	int n = container->size(); //size of container

	for( i = 0; i < n - 1; ++i ) { // same as above for now
		for( j = 0; j < n - i - 1; ++j ) { // starting at j, and as long as size - i - 1
			if( container->at(j)->evaluate() >  container->at(j + 1)->evaluate()) {
				container->swap(j, j+1);
			}
		}
	}
}
