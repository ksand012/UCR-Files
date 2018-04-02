#include "Connector.h"
#include "Semicolon.h"

Semicolon::Semicolon(Base* lefty, Base* righty): Connector(lefty,righty) {}
Semicolon::Semicolon(): Connector() {}
bool Semicolon::doCommand() {
    lefty->doCommand();
    if(righty->doCommand()) {
        return true;
    }
    else {
        return false;
   }
}
