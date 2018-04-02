#include <iostream>
#include <cstring>
#include "vector_container.h"
#include "list_container.h"
#include "strategy.h"
#include "op.h"
#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "divide.h"
#include "square.h"
#include "decorator.h"
#include "doubleprint.h"
#include "hexprint.h"
#include "binaryprint.h"
#include "doublefactory.h"
#include "hexfactory.h"
#include "binaryfactory.h"

using namespace std;

int main(int argc, char* argv[]) {
	BaseFactory* TEST;

	if (strcmp(argv[1], "d") == 0) {
		TEST = new DoubleFactory();
	}
	else if (strcmp(argv[1], "h") == 0) {
		TEST = new HexFactory();
	}
	else if (strcmp(argv[1], "b") == 0) {
		TEST = new BinaryFactory();
	}

    Op* op1 = new Op(5);
    Op* op2 = new Op(2);
    Op* op3 = new Op(4);
    Op* op4 = new Op(6);
	Op* op5 = new Op(7);
	Absolute* Z = new Absolute(op5);
    Multiply* A = new Multiply(op1, op2);
    Subtract* B = new Subtract(op3, op4);
    Add* C = new Add(A, B);
    Square* D = new Square(C);
    //VectorContainer* container = new VectorContainer(TEST);
    ListContainer* container = new ListContainer(TEST);
    container->add_element(op1);
    container->add_element(B);
    container->add_element(D);
	container->add_element(Z);
    cout << "Container Before Sort: " << endl;
	container->print();
    container->set_sort_function(new SelectionSort());
    container->sort();	
    cout << "Container After Sort: " << endl;
	container->print();

	int apple;
	cin >> apple;
};
