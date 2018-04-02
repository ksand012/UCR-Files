#include "component.h"
#include "subtract.h"

Subtract::Subtract() {
	this->lhs = 0;
	this->rhs = 0;
}

Subtract::Subtract(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Subtract::evaluate() {
	return this->lhs->evaluate() - this->rhs->evaluate();
}