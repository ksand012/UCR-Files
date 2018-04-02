#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>
#include "Connector.h"
#include "OutOne.h"

using namespace std;

OutOne::OutOne(Base* lefty, Base* righty) : Connector(lefty, righty) {}
OutOne::OutOne() : Connector() {}

bool OutOne::doCommand(int in, int out) {
	string outfile = righty->findFunction();
	out = open(outfile.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

	return lefty->doCommand(0, out);
}