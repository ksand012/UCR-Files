#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

#include <stdexcept>

using namespace std;

class IntVector
{
    private:
    unsigned sz;
    //stores the size of the IntVector (the number of elements currently being used).
    unsigned cap;
    //store the size of the array
    int *data; 
    //stores the address of the dynamically-allocated array of integers
    public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    const int & front() const;
    const int & back() const;
    
    
};

#endif