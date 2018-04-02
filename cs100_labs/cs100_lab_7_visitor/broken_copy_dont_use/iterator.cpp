#include "iterator.h"

/* Operator Iterator */

void OperatorIterator::first() {
    this->current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
    if(this->current_ptr == self_ptr->get_left())
        this->current_ptr = self_ptr->get_right();
    else
        this->current_ptr = NULL;
}

bool OperatorIterator::is_done() {
    return this->current_ptr == NULL;
}

Base* OperatorIterator::current() {
    return this->current_ptr;
}

/* Unary Iterator */

void UnaryIterator::first() {
        this->current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
    this->current_ptr = NULL;
}

bool UnaryIterator::is_done() {
    return this->current_ptr == NULL;
}

Base* UnaryIterator::current() {
    return this->current_ptr;
}

/* Null Iterator */

void NullIterator::first() { }

void NullIterator::next() { }

bool NullIterator::is_done() {return true;}    //always returns true

Base* NullIterator::current() {return NULL;}


/* Preorder Iterator */

// Empty the stack (just in case we had something leftover from another run)
// Create an iterator for the Base* that we built the iterator for
// Initialize that iterator and push it onto the stack
void PreorderIterator::first() {
    while(!this->iterators.empty())
    {
        Iterator* temp = iterators.top();
        iterators.pop();
        delete temp;
    }

    Iterator* iter = this->self_ptr->create_iterator();
    iter->first();
    this->iterators.push(iter);
}

// Create an iterator for the item on the top of the stack
// Initialize the iterator and push it onto the stack
// As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
void PreorderIterator::next() {
    Iterator* iter = this->iterators.top()->current()->create_iterator();

    iter->first();
    this->iterators.push(iter);

    while(!this->iterators.empty() && this->iterators.top()->is_done()){
        delete this->iterators.top();
        iterators.pop();
        if(this->iterators.empty())
            break;
        this->iterators.top()->next();
    }
}

// Return true if there are no more elements on the stack to iterate
bool PreorderIterator::is_done() {
    return this->iterators.empty();
}

// Return the current for the top iterator in the stack
Base* PreorderIterator::current() {
    if(!this->iterators.empty())
        return this->iterators.top()->current();
    return NULL;
}