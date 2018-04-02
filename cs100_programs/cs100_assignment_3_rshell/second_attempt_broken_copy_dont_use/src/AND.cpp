#include "AND.h"

AND::AND(Base* lefty, Base* righty): Connector(lefty,righty) {}
AND::AND(): Connector() {}
bool AND::doCommand() {
    if(lefty->doCommand()){
       if(righty->doCommand()){
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
