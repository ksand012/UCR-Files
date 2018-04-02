#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include "Connector.h"
#include "Pipe.h"

using namespace std;

Pipe::Pipe(Base* lefty, Base* righty) : Connector(lefty, righty) {}
Pipe::Pipe() : Connector() {}

bool Pipe::doCommand(int in, int out) {
	int fds[2];
	if (pipe(fds) == -1) {
		perror("pipe");
		return false;
	}
	if (!lefty->doCommand(in, fds[1])) {
		return false;
	}
	close(fds[1]);
	if (!righty->doCommand(fds[0], out)) {
		return false;
	}
	close(fds[0]);
	return true;
}