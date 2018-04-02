#include "component.h"
#include "divide.h"

Divide::Divide() {
	this->lhs = 0;
	this->rhs = 0;
}

Divide::Divide(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Divide::evaluate() {
	return this->lhs->evaluate() / this->rhs->evaluate();
}