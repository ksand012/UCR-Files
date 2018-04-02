#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include "Base.h"
#include "Cmd.h"
#include "Connector.h"
#include "AND.h"
#include "OR.h"
#include "Semicolon.h"
#include "Exit.h"
#include "Test.h"
#include "Tree.h"

using namespace std;

const string AND_STRING = "&&";
const string OR_STRING = "||";
const string SEMI_STRING = ";";

Tree::Tree()
{}

Tree::Tree(char* p)
{}

void Tree::splitUpFirstCharacter(char* p) {
	string tempP = string(p);
	tempP = tempP.substr(1, tempP.size() - 1);
	strcpy(p, tempP.c_str());
}

void Tree::splitUpLastCharacter(char* p) {
	string tempP = string(p);
	size_t comments = tempP.find('#');
	size_t comma = tempP.find(';');
	if (comma != std::string::npos || comments != std::string::npos) {
		tempP.erase(tempP.end() - 2);
	}
	else {
		tempP.erase(tempP.end() - 1);
	}
	strcpy(p, tempP.c_str());
}

void Tree::splitUpLastCharacterAlways(char *p) {
	string tempP = string(p);
	tempP.erase(tempP.end() - 1);
	strcpy(p, tempP.c_str());
}

bool Tree::checkCon(char *q) {
	vector<string> s;
	s.push_back("&&");
	s.push_back("||");
	for (unsigned i = 0; i<s.size(); i++)
		if (q == s.at(i))
			return false;
	return true;
}

bool Tree::checkAllCon(char *q) {
	vector<string> s;
	s.push_back("&&");
	s.push_back("||");
	s.push_back("#");
	s.push_back(";");

	for (unsigned i = 0; i<s.size(); i++)
		if (q == s.at(i))
			return false;
	return true;
}

Base* Tree::grabTree(char *cstr) {
	queue<Base *> commandList;
	queue<char *> connectorList;
	queue<Connector *> completedListToRun;
	char *p = strtok(cstr, " ");
	bool firstArgSemi = false;
	char *checkingSemi = (char *)memchr(p, ';', strlen(p));
	char *checkingComment = (char *)memchr(p, '#', strlen(p));
	char *checkingTest = (char *)memchr(p, '[', strlen(p));
	string checkingStringTest = string(p);
	if (checkingSemi != NULL) {
		string tempP = string(p);
		tempP = tempP.substr(0, tempP.size() - 1);
		strcpy(p, tempP.c_str());
		string semiCol = ";";
		char *pushConnector = new char[2];
		strcpy(pushConnector, semiCol.c_str());
		connectorList.push(pushConnector);
		firstArgSemi = true;
	}
	if (checkingStringTest.compare("test") == 0) {
		p = strtok(NULL, " ");
		Test *c = new Test();
		char *checkFlag = (char *)memchr(p, '-', strlen(p));
		if (checkFlag != NULL) {
			c->addFlag(p);
			p = strtok(NULL, " ");
			c->addFlag(p);
			p = strtok(NULL, " ");
		}
		else {
			c->addFlag(p);
			p = strtok(NULL, " ");
		}
		commandList.push(c);
		if (p != 0) {
			bool checkingConnectors = checkAllCon(p);
			char *commentP = (char *)memchr(p, '#', strlen(p));

			if (commentP != NULL) {
				checkingComment = commentP;
			}
			else if (checkingConnectors) {
				cout << "Error: Expected a connector, Received: " << p << endl;
				exit(1);
			}
			else {
				connectorList.push(p);
				p = strtok(NULL, " ");
			}
		}
	}
	if (checkingTest != NULL) {
		Test *c = new Test();
		p = strtok(NULL, " ");
		char *checkFlag = (char *)memchr(p, '-', strlen(p));
		if (checkFlag != NULL) {
			c->addFlag(p);
			p = strtok(NULL, " ");
			c->addFlag(p);
			p = strtok(NULL, " ");
		}
		else {
			c->addFlag(p);
			p = strtok(NULL, " ");
		}
		if (p != 0) {
			char *checkingEndTest = (char *)memchr(p, ']', strlen(p));
			if (checkingEndTest == NULL) {
				cout << "Error: Expected: ']', Received: " << p << endl;
				exit(1);
			}
		}
		p = strtok(NULL, " ");
		commandList.push(c);

		if (p != 0) {
			bool checkingConnectors = checkAllCon(p);
			if (checkingConnectors) {
				cout << "Error: Expected a connector, Received: " << p << endl;
				exit(1);
			}
			char *commentP = (char *)memchr(p, '#', strlen(p));
			if (commentP != NULL) {
				checkingComment = commentP;
			}
			else {
				connectorList.push(p);
				p = strtok(NULL, " ");
			}
		}
	}
	if (checkingComment == NULL) {
		bool commentDetected = false;
		while (p != 0 && !commentDetected) {
			char *commentP = (char *)memchr(p, '#', strlen(p));
			if (commentP != NULL) {
				commentDetected = true;
				break;
			}
			string checkingStringTest = string(p);
			if (checkingStringTest.compare("test") == 0) {
				p = strtok(NULL, " ");
				Test *c = new Test();
				char *checkFlag = (char *)memchr(p, '-', strlen(p));
				if (checkFlag != NULL) {
					c->addFlag(p);
					p = strtok(NULL, " ");
					c->addFlag(p);
					p = strtok(NULL, " ");
				}
				else {
					c->addFlag(p);
					p = strtok(NULL, " ");
				}
				commandList.push(c);
				if (p != 0) {
					bool checkingConnectors = checkAllCon(p);
					char *commentP = (char *)memchr(p, '#', strlen(p));
					if (commentP != NULL) {
						checkingComment = commentP;
					}
					else if (checkingConnectors) {
						cout << "Error: Expected a connector, Received: " << p << endl;
						exit(1);
					}
					else {
						connectorList.push(p);
						p = strtok(NULL, " ");
					}
				}
				else {
					break;
				}
			}
			char *testingTest = (char *)memchr(p, '[', strlen(p));
			if (testingTest != NULL) {
				Test *c = new Test();
				p = strtok(NULL, " ");
				for (unsigned i = 0; i<2; i++) {
					c->addFlag(p);
					p = strtok(NULL, " ");
				}
				if (p != 0) {
					char *checkingEndTest = (char *)memchr(p, ']', strlen(p));
					if (checkingEndTest == NULL) {
						cout << "Error: Expected: ']', Received: " << p << endl;
						exit(1);
					}
				}
				p = strtok(NULL, " ");
				commandList.push(c);
				if (p != 0) {
					bool checkingConnectors = checkAllCon(p);
					if (checkingConnectors) {
						cout << "Error: Expected a connector, Received: " << p << endl;
					}
					char *commentP = (char *)memchr(p, '#', strlen(p));
					if (commentP != NULL) {
						checkingComment = commentP;
					}
					else {
						connectorList.push(p);
						p = strtok(NULL, " ");
					}
				}
				else {
					break;
				}
			}
			Cmd *testingCommand = new Cmd(p);
			char *q = p;
			if (!firstArgSemi && !commentDetected) {
				q = strtok(NULL, " ");
				while (q != 0 && !commentDetected) {
					bool checkConnectors = checkCon(q);
					char *comment = (char *)memchr(q, '#', strlen(q));
					if (comment != NULL) {
						commentDetected = true;
					}
					else {
						if (checkConnectors) {
							char *semi = (char *)memchr(q, ';', strlen(q));
							char *com = (char *)memchr(q, '#', strlen(q));

							if (semi != NULL) {
								string tempQ = string(q);
								tempQ = tempQ.substr(0, tempQ.size() - 1);
								strcpy(q, tempQ.c_str());

								testingCommand->addFlag(q);

								string Colon = ";";
								char *pushColon = new char[2];
								strcpy(pushColon, Colon.c_str());
								connectorList.push(pushColon);
								break;
							}
							if (com != NULL) {
								commentDetected = true;
								break;
							}
							else {
								testingCommand->addFlag(q);
							}
						}
						else {
							char *com1 = (char *)memchr(q, '#', strlen(q));
							if (com1 != NULL) {
								commentDetected = true;
								break;
							}

							if (!checkConnectors) {
								connectorList.push(q);
							}
							break;
						}
					}
					q = strtok(NULL, " ");
				}
				p = q;
				p = strtok(NULL, " ");
				if (testingCommand->findFunction() == "exit") {
					Exit *out = new Exit();
					commandList.push(out);
				}
				else {
					commandList.push(testingCommand);
				}
			}
			else {
				commandList.push(testingCommand);
				p = q;
				p = strtok(NULL, " ");
				firstArgSemi = false;
			}
		}
		if (connectorList.size() > 0) {
			Base *lhs = commandList.front();
			commandList.pop();
			Base *rhs = commandList.front();
			commandList.pop();
			char *temp = connectorList.front();
			connectorList.pop();
			if (temp == AND_STRING) {
				AND *n = new AND(lhs, rhs);
				completedListToRun.push(n);
			}
			if (temp == OR_STRING) {
				OR *n = new OR(lhs, rhs);
				completedListToRun.push(n);
			}
			if (temp == SEMI_STRING) {
				Semicolon *n = new Semicolon(lhs, rhs);
				completedListToRun.push(n);
			}
			while (connectorList.size() != 0) {
				Connector *tempLHS = completedListToRun.front();
				completedListToRun.pop();
				Base *rhs = commandList.front();
				commandList.pop();
				char *temp2 = connectorList.front();
				connectorList.pop();
				if (temp2 == AND_STRING) {
					AND *n = new AND(tempLHS, rhs);
					completedListToRun.push(n);
				}
				else if (temp2 == OR_STRING) {
					OR *n = new OR(tempLHS, rhs);
					completedListToRun.push(n);
				}
				else if (temp2 == SEMI_STRING) {
					Semicolon *n = new Semicolon(tempLHS, rhs);
					completedListToRun.push(n);
				}
			}
			Connector *singleRun = completedListToRun.front();
			completedListToRun.pop();
			return singleRun;
		}
		else {
			if (commandList.size() != 1) {
				cout << "Error commandList has more than 1 Cmd*" << endl;
				exit(1);
			}
			else {
				Base *temporaryCmd = commandList.front();
				commandList.pop();
				return temporaryCmd;
			}
		}
	}
	if (commandList.size() > 1) {
		cout << "Error commandList has more than 1 Cmd*" << endl;
		exit(1);
	}
	else {
		Base* resultCmd = commandList.front();
		commandList.pop();
		return resultCmd;
	}
	return NULL;
}
