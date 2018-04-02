#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>
#include "Connector.h"
#include "OutTwo.h"

using namespace std;

OutTwo::OutTwo(Base* lefty, Base* righty) : Connector(lefty, righty) {}
OutTwo::OutTwo() : Connector() {}

bool OutTwo::doCommand(int in, int out) {
	string outfile = righty->findFunction();
	out = open(outfile.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	return lefty->doCommand(0, out);
}