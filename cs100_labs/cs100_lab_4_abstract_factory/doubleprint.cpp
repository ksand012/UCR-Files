#include "doubleprint.h"
#include <iostream>

using namespace std;

DoublePrint::DoublePrint() {
	this->value = 0;
}

DoublePrint::DoublePrint(double x) {
	this->value = x;
}

void DoublePrint::print() {
	cout << value << endl;
}