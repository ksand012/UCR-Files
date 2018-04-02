#ifndef __CMD_H__
#define __CMD_H__

#include <queue>
#include <string>
#include "Base.h"

using namespace std;

class Cmd: public Base {
    protected:
    char *function;
    queue<char*> flag;
    public:
    Cmd(char *function, queue<char*> flag);
    Cmd(queue<char*> flag);
    Cmd(char *function);
    Cmd();
    void addFlag(char *i);
    virtual bool doCommand(int in, int out);
    string findFunction();
};
#endif
