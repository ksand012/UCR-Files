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

//constructors
Cmd::Cmd(char* command, queue<char *> flags) {
    this->command = command;
    this->flags = flags;
}

Cmd::Cmd(queue<char*> flags) {
    this->flags = flags;
}

Cmd::Cmd(char* command) {
    this->command = command;
    queue<char*> temp;
    this->flags = temp;
}

Cmd::Cmd() {}

//push any new flags into the queue<char *> flags
void Cmd::add_flag(char*a) {
    flags.push(a);
}

//Used for the Exit Command to fix Exit bug
string Cmd::getCommand() {
    return command;
}

/*For Debugging Purposes
void Cmd::printFlags()   {

    for(unsigned i=0; i<flags.size(); i++)  {
        cout << flags.at(i) << " ";
    }
}*/

//executes the command using the system calls fork
//execvp and wait returns true if the command is executed
//and false if it fails
bool Cmd::execute() {
    //c-string array to pass to execvp
    //flags.push_back(NULL);

    flags.push(NULL);
    int ctr = 1;
    char *args[500];
    while(flags.size() != 0) {
        args[ctr] = flags.front();
        flags.pop();
        ctr++;
    }

    args[0] = command; //Setting the Command to args[0] for execvp
    //return value of the function
    //true if command executes
    bool ret = true;

    pid_t pid = fork();                         //Creating child process
    if(pid == -1) {                             //if fork() fails
        perror("fork");                         //run error checking
    }
    else if (pid == 0) {                        //Otherwise work on child process
        if(execvp(args[0], args) == -1) {       //if child fail, perform error checking and return false and exit
            ret = false;
            perror("execvp");
            exit(1);
        }
    }
    else if(pid > 0) {                          //Otherwise continue to the parent process
       int status;
       if(waitpid(pid,&status,0) == -1) {       //pause the parent process
           perror("wait");
       }
       if(WEXITSTATUS(status) != 0) {           //Zombiessssssssssssssss
           ret = false;
       }

    }
    return ret;
}
