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

int main(int argc, char**argv) {
    for(; ;) {
        string userInput;
        getline(cin, userInput);
        if(userInput == "exit") {
            Exit *exit = new Exit();
            exit->doCommand();
            break;
        }
        char *cstr = new char[userInput.size()+1];
        strcpy(cstr, userInput.c_str());
        queue<Base *> precedenceTrees;
        queue<Connector *> outsideConnectors;
        size_t foundPrecedence = userInput.find('(');
        size_t foundTest = userInput.find('[');
        if(foundPrecedence!=std::string::npos || (foundPrecedence!=std::string::npos && foundTest!=std::string::npos)) {
            string totalString = "";
            char *p = strtok(cstr, " ");
			Tree *superTree = new Tree(p);
            while(p!=0) {
                char *checkingPrecedenceF = (char *) memchr(p, '(', strlen(p));
                char *checkingPrecedenceE = (char *) memchr(p, ')', strlen(p));
                char *checkingTestB = (char *) memchr(p, '[', strlen(p));
                char *checkingTestE = (char *) memchr(p, ']', strlen(p));
                int totalEndingPrecedence = 0;
                if(checkingPrecedenceF != NULL && checkingPrecedenceF != NULL && checkingTestB != NULL && checkingTestE != NULL) {
                    while(checkingPrecedenceF != NULL) {
                        totalString += "( ";
                        superTree->splitUpFirstCharacter(p);
                        checkingPrecedenceF = (char *) memchr(p, '(', strlen(p));
                    }
                    totalString += "[ ";
					superTree->splitUpFirstCharacter(p);
                    while(checkingPrecedenceE != NULL) {
                        totalEndingPrecedence++;
						superTree->splitUpLastCharacter(p);
                        checkingPrecedenceE = (char *) memchr(p, ')', strlen(p));
                    }
                    char *checkingComma = (char *) memchr(p, ';', strlen(p));
                    char *checkingComment = (char *) memchr(p, '#', strlen(p));
                    if(checkingComma != NULL || checkingComment != NULL) {
						superTree->splitUpLastCharacterAlways(p);
                        totalString += string(p);
                        totalString += " ";
                        for(int i=0; i<totalEndingPrecedence; i++) {
                            totalString += ") ";
                        }
                        if(checkingComma != NULL) {
                            totalString += "; ";
                        }
                        else {
                            totalString += "# ";
                        }
                    }
                    else {
						superTree->splitUpLastCharacterAlways(p);
                        totalString += string(p);
                        totalString += " ";
                        totalString += "] ";
                        for(int i=0; i<totalEndingPrecedence; i++) {
                            totalString += ") ";
                        }
                    }
                }
                else if(checkingPrecedenceF != NULL && checkingTestB != NULL) {
                    while(checkingPrecedenceF != NULL) {
                        totalString += "( ";
                        checkingPrecedenceF = (char *) memchr(p, '(', strlen(p));
						superTree->splitUpFirstCharacter(p);
                    }
                    totalString += "[ ";
                    totalString += string(p);
                    totalString += " ";
                }
                else if(checkingTestB != NULL && checkingTestE != NULL) {
                    totalString += "[ ";
					superTree->splitUpFirstCharacter(p);
					superTree->splitUpLastCharacter(p);
                    totalString += string(p);
                    totalString += " ";
                    totalString += "] ";
                }
                else if(checkingTestB != NULL) {
                    totalString += "[ ";
					superTree->splitUpFirstCharacter(p);
                    totalString += string(p);
                    totalString += " ";
                }
                else if(checkingTestE != NULL) {
					superTree->splitUpLastCharacter(p);

                    totalString += string(p);
                    totalString += " ";
                    totalString += "] ";
                }
                else if(checkingPrecedenceF != NULL) {
                    while(checkingPrecedenceF != NULL) {
                        totalString += "( ";
						superTree->splitUpFirstCharacter(p);
                        checkingPrecedenceF = (char *) memchr(p, '(', strlen(p));
                    }
                    totalString += string(p);
                    totalString += " ";
                }
                else if(checkingPrecedenceE != NULL) {
                    while(checkingPrecedenceE != NULL) {
                        totalEndingPrecedence++;
						superTree->splitUpLastCharacter(p);
                        checkingPrecedenceE = (char *) memchr(p, ')', strlen(p));
                    }
                    char *checkingComma = (char *) memchr(p, ';', strlen(p));
                    char *checkingComment = (char *) memchr(p, '#', strlen(p));
                    if(checkingComma != NULL || checkingComment != NULL) {
						superTree->splitUpLastCharacterAlways(p);
                        totalString += string(p);
                        totalString += " ";
                        for(int i=0; i<totalEndingPrecedence; i++) {
                            totalString += ") ";
                        }
                        if(checkingComma != NULL) {
                            totalString += "; ";
                        }
                        else {
                            totalString += "# ";
                        }
                    }
                    else {
                        totalString += string(p);
                        totalString += " ";
                        for(int i=0; i<totalEndingPrecedence; i++) {
                            totalString += ") ";
                        }
                    }
                }
                else {
                    totalString += string(p);
                    totalString += " ";
                }
                p = strtok(NULL, " ");
            }
            char *totalChar = new char[totalString.size()+1];
            strcpy(totalChar, totalString.c_str());
            char *c = strtok(totalChar, " ");
	        stack<char *> stringStack;
	        queue<string> branches;
	        queue<char *> connectors;
	        bool withinPrecedence = false;
	        bool newPrecedence = false;
	        while(c!=0) {
	            char *beginPrecedence = (char *) memchr(c, '(', strlen(c));
	            char *endPrecedence = (char *) memchr(c, ')', strlen(c));
				Tree *superCTree = new Tree(c);
	            bool checkConnectors = superCTree->checkAllCon(c);
	            if(beginPrecedence != NULL) {
	                withinPrecedence = true;
	                if(!newPrecedence) {
	                    stack<char *> currentString;
	                    while(!stringStack.empty()) {
	                        char *a = stringStack.top();
	                        char *checkingStartPrecedence = (char *) memchr(a, '(', strlen(a));
	                        if(checkingStartPrecedence != NULL) {
	                            stringStack.pop();
	                            break;
	                        }
	                        currentString.push(a);
	                        stringStack.pop();
	                    }
	                    string finalString;
	                    while(!currentString.empty()) {
	                        finalString += currentString.top();
	                        finalString += " ";
	                        currentString.pop();
	                    }
	                    if(finalString.size() > 0) {
	                        branches.push(finalString);
	                    }
	                }
	                newPrecedence = true;
	            }
	            else if(endPrecedence != NULL) {
	                withinPrecedence = false;
	                newPrecedence = false;
	                stack<char *> currentString;
	                while(!stringStack.empty()) {
	                    char *a = stringStack.top();
	                    char *checkingStartPrecedence = (char *) memchr(a, '(', strlen(a));
	                    if(checkingStartPrecedence != NULL) {
	                        stringStack.pop();
	                        break;
	                    }
	                    currentString.push(a);
	                    stringStack.pop();
	                }
	                string finalString;
	                while(!currentString.empty()) {
	                    finalString += currentString.top();
	                    finalString += " ";
	                    currentString.pop();
	                }
	                if(finalString.size() > 0) {
	                    branches.push(finalString);
	                }
	            }
	            else if(!checkConnectors && !withinPrecedence) {
	                connectors.push(c);
	            }
	            else {
	                stringStack.push(c);
	            }
	            c = strtok(NULL, " ");
	        }
	        stack<char *> currentOvers;
	        while(!stringStack.empty()) {
	            currentOvers.push(stringStack.top());
	            stringStack.pop();
	        }
	        string leftOvers;
	        while(!currentOvers.empty()) {
	            leftOvers += currentOvers.top();
	            leftOvers += " ";
	            currentOvers.pop();
	        }
	        if(leftOvers.size() != 0) {
	            branches.push(leftOvers);
	        }
	        queue<Base *> commandTreeList;
	        while(!branches.empty()) {
	            char *r = new char[branches.front().size()+1];
	            strcpy(r, branches.front().c_str());
				Tree *superRTree = new Tree(r);
	            branches.pop();
	            Base* tree = superRTree->grabTree(r);
                if(tree != NULL) {
                    commandTreeList.push(tree);
	            }
	        }
            if(connectors.size() > 0) {
                queue<Connector *>completedListToRun;
                Base* lhs = commandTreeList.front();
                commandTreeList.pop();
                Base* rhs = commandTreeList.front();
                commandTreeList.pop();
                char *temp = connectors.front();
                connectors.pop();
                if(temp == AND_STRING) {
                    AND *n = new AND(lhs, rhs);
                    completedListToRun.push(n);
                }
                else if(temp == OR_STRING) {
                    OR *n = new OR(lhs, rhs);
                    completedListToRun.push(n);
                }
                else if(temp == SEMI_STRING) {
                    Semicolon *n = new Semicolon(lhs, rhs);
                    completedListToRun.push(n);
                }
                while(connectors.size() > 0) {
                    Connector *tempLHS = completedListToRun.front();
                    completedListToRun.pop();
                    Base *rhs = commandTreeList.front();
                    commandTreeList.pop();
                    char *temp2 = connectors.front();
                    connectors.pop();
                    if(temp2 == AND_STRING) {
                        AND *n = new AND(tempLHS, rhs);
                        completedListToRun.push(n);
                    }
                    else if(temp2 == OR_STRING) {
                        OR *n = new OR(tempLHS, rhs);
                        completedListToRun.push(n);
                    }
                    else if(temp2 == SEMI_STRING) {
                        Semicolon *n = new Semicolon(tempLHS, rhs);
                        completedListToRun.push(n);
                    }
                }
                Connector *singleRun = completedListToRun.front();
                completedListToRun.pop();
                singleRun->doCommand();
           }
           else {
                Base* s = commandTreeList.front();
                commandTreeList.pop();
                if(commandTreeList.size() != 0) {
                    cout << "Error: commandTreeList.size() != 0" << endl;
                    exit(1);
                }
                s->doCommand();
            }
        }
        else {
            size_t foundTest = userInput.find('[');
            if(foundTest!=std::string::npos) {
                string totalString = "";
                char *p = strtok(cstr, " ");
				Tree *super1Tree = new Tree(p);
                while(p!=0) {
                    char *checkingTestB = (char *) memchr(p, '[', strlen(p));
                    char *checkingTestE = (char *) memchr(p, ']', strlen(p));
                    if(checkingTestB != NULL && checkingTestE != NULL) {
                        totalString += "[ ";
						super1Tree->splitUpFirstCharacter(p);
						super1Tree->splitUpLastCharacter(p);
                        totalString += string(p);
                        totalString += " ";
                        totalString += "] ";
                    }
                    else if(checkingTestB != NULL) {
                        totalString += "[ ";
						super1Tree->splitUpFirstCharacter(p);
                        totalString += string(p);
                        totalString += " ";
                    }
                    else if(checkingTestE != NULL) {
						super1Tree->splitUpLastCharacter(p);
                        totalString += string(p);
                        totalString += " ";
                        totalString += "] ";
                    }
                    else {
                        totalString += string(p);
                        totalString += " ";
                    }
                    p = strtok(NULL, " ");
                }
	            char *r = new char[totalString.size()+1];
				Tree *superR1Tree = new Tree(r);
	            strcpy(r, totalString.c_str());
                Base *s = superR1Tree->grabTree(r);
                s->doCommand();
            }
            else {
				Tree *superCstrTree = new Tree(cstr);
                Base* s = superCstrTree->grabTree(cstr);
                s->doCommand();
            }
        }
        delete[] cstr;
    }
    return 0;
}
