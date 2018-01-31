#include "IntVector.h"    
    
    /*private:
    unsigned sz;
    //stores the size of the IntVector (the number of elements currently being used).
    unsigned cap;
    //store the size of the array
    int *data; 
    //stores the address of the dynamically-allocated array of integers
    */
    
    
    IntVector::IntVector()
    {
        this->sz = 0;
        this->cap = 0;
        this->data = 0;
    }
    IntVector::IntVector(unsigned size, int value)
    {
        this->sz = size;
        this->cap = size;
        this->data = new int[this->sz];
        
        for(unsigned i = 0; i < this->size(); i++)
        {
            data[i] = value;
        }
    }
    IntVector::~IntVector()
    {
        delete [] this->data;
    }
    unsigned IntVector::size() const
    {
        return this->sz;
    }
    
    
    unsigned IntVector::capacity() const
    {
        return this->cap;
    }
    
    bool IntVector::empty() const
    {
        if(this->sz == 0)
        return true;
        
        return false;
    }
    const int & IntVector::at(unsigned index) const
    {
        if(index >= this->size())
        throw out_of_range("IntVector::at_range_check");
        
        return data[index];
    }
    const int & IntVector::front() const
    {
        return data[0];
    }
    const int & IntVector::back() const
    {
        return data[this->size()-1];
    }