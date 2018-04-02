#include "Cmd.h"
#include "Exit.h"
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h> 

Exit::Exit()
{}

bool Exit::doCommand() {
    exit(0);
}