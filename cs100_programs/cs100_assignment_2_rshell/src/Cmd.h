#ifndef __CMD_H__
#define __CMD_H__

#include <queue>
#include <string>

#include "Base.h"

using namespace std;

class Cmd: public Base {
    protected:
    char *command; //name of the command
    queue<char*> flags; //vector holding the flags provided
    public:
    //constructors
    Cmd(char *command, queue<char*> flags);
    Cmd(queue<char*> flags);
    Cmd(char *command);
    Cmd();

    //Adds a flag based on the container that is used (I.E. queue)
    void add_flag(char *a);
    //executes the command using the system calls fork
    //execvp and wait returns true if the command is executed
    //and false if it fails
    virtual bool execute();


    //For Debugging Purposes
    string getCommand();

    //void printFlags();
};
#endif
