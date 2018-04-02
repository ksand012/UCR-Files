#include "Connector.h"
#include "OR.h"

OR::OR(Base* lefty, Base* righty): Connector(lefty,righty) {}
OR::OR(): Connector() {}
bool OR::doCommand() {
    if(!lefty->doCommand()) {
        if(righty->doCommand()) {
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}
