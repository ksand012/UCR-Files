#include <stdexcept>
#include <iostream>
#ifndef __I_V_H__
#define __I_V_H__
using namespace std;

class IntVector
{
private:
    //stores the size of the IntVector (the number of elements currently being used).
    unsigned sz;
    //store the size of the array
    unsigned cap;
    //stores the address of the dynamically-allocated array of integers
    int *data;
    void expand();
    void expand(unsigned amount);
    
public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    int & at(unsigned index);
    void insert(unsigned index, int value);
    void erase(unsigned index);
    const int & front() const;
    int & front();
    const int & back() const;
    int & back();
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned size, int value = 0);
    void reserve(unsigned n);
    
    
};

#endif