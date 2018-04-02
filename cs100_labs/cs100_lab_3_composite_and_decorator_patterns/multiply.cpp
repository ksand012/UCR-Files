#include "component.h"
#include "multiply.h"

Multiply::Multiply() {
	this->lhs = 0;
	this->rhs = 0;
}

Multiply::Multiply(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Multiply::evaluate() {
	return this->lhs->evaluate() * this->rhs->evaluate();
}
