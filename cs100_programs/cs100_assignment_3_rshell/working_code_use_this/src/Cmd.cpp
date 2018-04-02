#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include "Base.h"
#include "Cmd.h"

using namespace std;

Cmd::Cmd(char* function, queue<char *> flag) {
	this->function = function;
	this->flag = flag;
}

Cmd::Cmd(queue<char*> flag) {
	this->flag = flag;
}

Cmd::Cmd(char* function) {
	this->function = function;
	queue<char*> temp;
	this->flag = temp;
}

Cmd::Cmd() {}

void Cmd::addFlag(char*i) {
	flag.push(i);
}

string Cmd::findFunction() {
	return function;
}

bool Cmd::doCommand() {

	flag.push(NULL);
	int iterator = 1;
	char *args[500];
	while (flag.size() != 0) {
		args[iterator] = flag.front();
		flag.pop();
		iterator++;
	}
	args[0] = function;
	bool returnValue = true;
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
	}
	else if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			returnValue = false;
			perror("execvp");
			exit(1);
		}
	}
	else if (pid > 0) {
		int status;
		if (waitpid(pid, &status, 0) == -1) {
			perror("wait");
		}
		if (WEXITSTATUS(status) != 0) {
			returnValue = false;
		}
	}
	return returnValue;
}
