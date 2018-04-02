#include "decorator.h"

Ceiling::Ceiling() {}

Ceiling::Ceiling(Base* x) : decorated(x) {}

double Ceiling::evaluate() {
	return ceil(decorated->evaluate());
}

Floor::Floor() {}

Floor::Floor(Base* x) : decorated(x) {}

double Floor::evaluate() {
	return floor(decorated->evaluate());
}

Absolute::Absolute() {}

Absolute::Absolute(Base* x) : decorated(x) {}

double Absolute::evaluate() {
	return fabs(decorated->evaluate());
}
