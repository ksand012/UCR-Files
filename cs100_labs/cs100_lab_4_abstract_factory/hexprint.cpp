#include "hexprint.h"
#include <iostream>

using namespace std;

HexPrint::HexPrint() {
	this->value = 0;
}

HexPrint::HexPrint(double x) {
	this->value = x;
}

void HexPrint::print() {
	cout /*<< std::hexfloat*/  << value /*<< std::defaultfloat*/ << endl;
}