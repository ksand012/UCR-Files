#include "visitor.h"

PrintVisitor::PrintVisitor()
{
    output = "";
}

void PrintVisitor::sqrNode()		//For visiting a square node
{
    output.append(" ^2 ");
}

void PrintVisitor::multNode()	//For visiting a multiple node
{
    output.append(" * ");
}

void PrintVisitor::subNode()		//For visiting a subtraction node
{
    output.append(" - ");
}

void PrintVisitor::addNode()		//For visiting an add node
{
    output.append(" + ");
}

void PrintVisitor::opNode(Op* op)	//For visiting a leaf node
{
    output.append(" ");
    ostringstream convert;
    convert << op->evaluate();
    output.append(convert.str());
    output.append(" ");
}


void PrintVisitor::execute()		//Prints all visited nodes
{
    cout << output << endl;
}

void PrintVisitor::rootNode() {

}