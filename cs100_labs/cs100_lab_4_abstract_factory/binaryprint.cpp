#include "binaryprint.h"
#include <bitset>
#include <iostream>

using namespace std;

BinaryPrint::BinaryPrint() {
	this->value = 0;
}

BinaryPrint::BinaryPrint(double x) {
	this->value = x;
}

void BinaryPrint::print() {
	std::bitset<16> val(value);
	cout << val << endl;
}

