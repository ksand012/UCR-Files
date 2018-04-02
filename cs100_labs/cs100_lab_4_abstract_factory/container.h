#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "component.h"
#include "basefactory.h"

class Sort;
class Container {
    protected: 
        Sort* sort_function;
		BaseFactory* factory;

    public: 
        /* Cosntructors */
        Container() : sort_function(0) { }
        Container(Sort* function); 

        /* Non Virtual Functions */
        // Set the type of sorting algorithm
        void set_sort_function(Sort* sort_function); 

        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container
        virtual void add_element(Base* element) = 0;
        // iterate through the trees and output values
        // calls on the previously set sorting-algorithm. 
        // Check if sort_function is not null, throw exception if is null
        virtual void sort() = 0;
		Container(BaseFactory* fact);
        /* Essentially the only functions needed to sort */
        // switch tree locations
        virtual void swap(int i,int j) = 0;
        // get top pointer of tree at index i
        virtual Base* at(int i) = 0;
        // return container size;
        virtual int size() = 0;
};

#endif // __CONTAINER_H__
