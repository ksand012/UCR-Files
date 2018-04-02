#include "Connector.h"
#include "Semicolon.h"

Semicolon::Semicolon(Base* lefty, Base* righty): Connector(lefty,righty) {}
Semicolon::Semicolon(): Connector() {}
bool Semicolon::doCommand(int in, int out) {
    lefty->doCommand(in, out);
    if(righty->doCommand(in, out)) {
        return true;
    }
    else {
        return false;
   }
}
