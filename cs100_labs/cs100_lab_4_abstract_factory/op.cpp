#include "component.h"
#include "op.h"

Op::Op() {
	this->value = 0;
}

Op::Op(double x) {
	this->value = x;
}

double Op::evaluate() {
	return this->value;
}