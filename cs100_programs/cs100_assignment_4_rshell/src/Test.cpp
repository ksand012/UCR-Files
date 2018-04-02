#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <dirent.h>
#include <iostream>
#include "Test.h"
#include "Base.h"

using namespace std;

Test::Test(char* function, queue<char *> flag) {
	this->function = function;
	this->flag = flag;
}

Test::Test(queue<char*> flag) {
	this->flag = flag;
}

Test::Test() {}

void Test::addFlag(char*i) {
	flag.push(i);
}

string Test::findFunction() {
	return function;
}

bool Test::doCommand(int in, int out) {
	struct stat buffer;
	string flagCurrent;
	string testPath;
	bool isFound = false;
	if (flag.size() == 1) {
		flagCurrent = "-e";
		testPath = flag.front();
	}
	else {
		flagCurrent = flag.front();
		flag.pop();
		testPath = flag.front();
	}
	
	int statusReturn = stat(testPath.c_str(), &buffer);
	if (statusReturn == 0) {
		isFound = true;
	}
	if (statusReturn == -1) {
		perror("stat");
		return false;
	}
	if (flagCurrent == "-e") {
		cout << "(true)" << endl;
		return isFound;
	}
	else if (flagCurrent == "-d") {
		if (S_ISDIR(buffer.st_mode)) {
			cout << "(true)" << endl;
			return true;
		}
		else {
			cout << "(false)" << endl;
			return false;
		}
	}
	else if (flagCurrent == "-f") {
		if (S_ISREG(buffer.st_mode)) {
			cout << "(true)" << endl;
			return true;
		}
		else {
			cout << "(false)" << endl;
			return false;
		}
	}
	else {
		cout << "Error: In test flag " << flagCurrent << " is not valid." << endl;
		return false;
	}
}