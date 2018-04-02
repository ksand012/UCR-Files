#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>
#include "Connector.h"
#include "In.h"

using namespace std;

In::In(Base* lefty, Base* righty) : Connector(lefty, righty) {}
In::In() : Connector() {}

bool In::doCommand(int in, int out) {
	string infile = righty->findFunction();
	in = open(infile.c_str(), O_RDONLY);
	return lefty->doCommand(in, 1);
}