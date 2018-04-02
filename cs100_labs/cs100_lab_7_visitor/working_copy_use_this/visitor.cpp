#include "composite.h"
#include "visitor.h"

PrintVisitor::PrintVisitor(){output = "";}
void PrintVisitor::rootNode() {}	//For visiting a root node (do nothing)
void PrintVisitor::sqrNode() { output.append(" ^2 "); }		//For visiting a square node
void PrintVisitor::multNode() { output.append(" * "); }	//For visiting a multiple node
void PrintVisitor::subNode() { output.append(" - "); }		//For visiting a subtraction node
void PrintVisitor::addNode() { output.append(" + "); }		//For visiting an add node
void PrintVisitor::opNode(Op* op){
	output.append(" ");
	ostringstream convert;
	convert << op->evaluate();
	output.append(convert.str());
	output.append(" ");}//For visiting a leaf node
void PrintVisitor::execute() { cout << output << endl; }		//Prints all visited nodes