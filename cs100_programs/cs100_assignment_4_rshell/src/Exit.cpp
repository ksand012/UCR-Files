#include "Cmd.h"
#include "Exit.h"
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h> 

Exit::Exit()
{}

bool Exit::doCommand(int in, int out) {
    exit(0);
}

string Exit::findFunction() {
	return "Exit";
}