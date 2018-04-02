#include "component.h"
#include "square.h"

Square::Square() {
	this->expression = 0;
}

Square::Square(Base* child) {
	this->expression = child;
}

double Square::evaluate() {
	return this->expression->evaluate() * this->expression->evaluate();
}