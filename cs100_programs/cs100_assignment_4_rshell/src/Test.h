#ifndef __TEST_H__
#define __TEST_H__
#include "Base.h"

using namespace std;

class Test: public Base {
    protected:
    char *function;
    queue<char*> flag;
	public:
    Test(char *function, queue<char*> flag);
    Test(queue<char*> flag);
    Test();
    void addFlag(char *i);
    virtual bool doCommand(int in, int out);
    string findFunction();
};
#endif
