#include "Cmd.h"
#include "Exit.h"

//Constructors
Exit::Exit()
{}

bool Exit::execute() {
    exit(0);
}

/*string Exit::get_data() {
    return "Exit";
}*/
