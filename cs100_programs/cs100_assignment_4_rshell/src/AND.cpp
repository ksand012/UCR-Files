#include "Connector.h"
#include "AND.h"

AND::AND(Base* lefty, Base* righty): Connector(lefty,righty) {}
AND::AND(): Connector() {}
bool AND::doCommand(int in, int out) {
    if(lefty->doCommand(in, out)){
       if(righty->doCommand(in, out)){
           return true;
       }
       else {
           return false;
       }
    }
    else {
        return false;
     }
}
