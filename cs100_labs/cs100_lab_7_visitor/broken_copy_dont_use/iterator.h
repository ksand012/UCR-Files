#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <stack>
#include <iostream>
#include "composite.h"

using namespace std;

class Base; //forward declaration

class Iterator {
protected:
    Base* self_ptr;
    Base* current_ptr;
public:
    explicit Iterator(Base* ptr) { this->self_ptr = ptr; }

    /* Sets up the iterator to start at the beginning of traversal */
    virtual void first() = 0;

    /* Move onto the next element */
    virtual void next() = 0;

    /* Returns if you have finished iterating through all elements */
    virtual bool is_done() = 0;

    /* Return the element the iterator is currently at */
    virtual Base* current() = 0;
};

class OperatorIterator : public Iterator {
public:
    explicit OperatorIterator(Base* ptr) : Iterator(ptr) { }

    void first() override;
    void next() override;
    bool is_done() override;
    Base* current() override;
};

class UnaryIterator : public Iterator {
public:
    explicit UnaryIterator(Base* ptr) : Iterator(ptr) { }

    void first() override;
    void next() override;
    bool is_done() override;
    Base* current() override;
};

class NullIterator : public Iterator {
public:
    explicit NullIterator(Base* ptr) : Iterator(ptr) { }

    void first() override;
    void next() override;
    bool is_done() override;
    Base* current() override;
};

class PreorderIterator : public Iterator {
protected:
    stack<Iterator*> iterators;
public:
    PreorderIterator(Base* ptr) : Iterator(ptr) { }

    void first() override;
    void next() override;
    bool is_done() override;
    Base* current() override;
};

#endif //__ITERATOR_H__