
#include "Connector.h"
#include "Semicolon.h"

//constructors
Semicolon::Semicolon(Base* lhs, Base* rhs): Connector(lhs,rhs) {}
Semicolon::Semicolon(): Connector() {}

//executes both of its children regardless of the success of the
//other child
//returns true or false based on the success of the right child
bool Semicolon::execute() {
    lhs->execute();
    if(rhs->execute()) {
        return true;
    }
    else {
        return false;
   }
}
