#include "Connector.h"
#include "OR.h"

OR::OR(Base* lefty, Base* righty): Connector(lefty,righty) {}
OR::OR(): Connector() {}
bool OR::doCommand(int in, int out) {
    if(!lefty->doCommand(in, out)) {
        if(righty->doCommand(in, out)) {
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}
