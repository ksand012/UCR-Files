/*
 * Base CPP File.
 *
 */

#include "component.h"
#include <iostream>

using namespace std;


Op::Op() {
	this->value = 0;
}

Op::Op(double x) {
	this->value = x;
}

double Op::evaluate() {
	return this->value;
}

Add::Add() {
	this->lhs = NULL;
	this->rhs = NULL;
}

Add::Add(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Add::evaluate() {
	return this->lhs->evaluate() + this->rhs->evaluate();
}

Subtract::Subtract() {
	this->lhs = NULL;
	this->rhs = NULL;
}

Subtract::Subtract(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Subtract::evaluate() {
	return this->lhs - evaluate() - this->rhs->evaluate();
}

Multiply::Multiply() {
	this->lhs = NULL;
	this->rhs = NULL;
}

Multiply::Multiply(Base* left, Base* right) {
	this->lhs = left;
	this->right = right;
}

double Multiply::evaluate() {
	return this->lhs->evaluate() * this->rhs->evaluate();
}

Divide::Divide() {
	this->lhs = NULL;
	this->rhs = NULL;
}

Divide::Divide(Base* left, Base* right) {
	this->lhs = left;
	this->rhs = right;
}

double Divide::evaluate() {
	return this->lhs->evaluate() / this->rhs->evaluate();
}

Square::Square() {
	this->expression = NULL;
}

Square::Square(Base* child) {
	this->expression = child;
}

double Square::evaluate() {
	return this->expression->evaluate() * this->expression->evaluate();
}
