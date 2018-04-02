#include "component.h"
#include "add.h"

Add::Add() {
	this->lhs = 0;
	this->rhs = 0;
}

Add::Add(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Add::evaluate() {
	return this->lhs->evaluate() + this->rhs->evaluate();
}