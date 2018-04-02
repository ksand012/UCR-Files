#include "iterator.h"
#include <stack>

void OperatorIterator::first() {
	//current_ptr points to left child of the node
	current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
	//current_ptr points to right child of the node for the first time, then points to NULL
	if (current_ptr == self_ptr) {
		current_ptr = self_ptr->get_left();
	}
	else if (current_ptr == self_ptr->get_left()) {
		current_ptr = self_ptr->get_right();
	}
	else {
		current_ptr = NULL;
	}
}

bool OperatorIterator::is_done() {
	if (current_ptr == NULL) {
		return true;
	}
	return false;
}

Base* OperatorIterator::current() {
	return current_ptr;
}

void UnaryIterator::first() {
	//first(): current_ptr points to child of the node
	current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
	//current_ptr points to NULL
	current_ptr = NULL;
}

bool UnaryIterator::is_done() {
	if (current_ptr == NULL) {
		return true;
	}
	return false;
}

Base* UnaryIterator::current() {
	return this->current_ptr;
}

void NullIterator::first() {
	//current_ptr points to NULL
	return;
}

void NullIterator::next() {
	//current_ptr points to NULL
	return;
}

bool NullIterator::is_done() {
	return true;
}

Base* NullIterator::current() {
	return NULL;
}

void PreOrderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
	while (!this->stacksOnStack.empty())
	{
		Iterator* temp = stacksOnStack.top();
		stacksOnStack.pop();
		delete temp;
	}

	Iterator* iter = this->self_ptr->create_iterator();
	iter->first();
	this->stacksOnStack.push(iter);
}

void PreOrderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
	Iterator *iter = stacksOnStack.top()->current()->create_iterator();
	iter->first();
	stacksOnStack.push(iter);
	while (!stacksOnStack.empty() && stacksOnStack.top()->is_done()) {
		stacksOnStack.pop();
		if (!stacksOnStack.empty()) {
			stacksOnStack.top()->next();
		}
	}
}


//////// JUST MAKING FUNNY COMMENTS - YOUR FAVORITE MCDONALDS MANAGER ;D

bool PreOrderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
	if (stacksOnStack.empty()) {
		return true;
	}
	return false;
}

Base* PreOrderIterator::current() {
    // Return the current for the top iterator in the stack
	if (!stacksOnStack.empty()) {
		return stacksOnStack.top()->current();
	}
	else {
		return NULL;
	}
}
