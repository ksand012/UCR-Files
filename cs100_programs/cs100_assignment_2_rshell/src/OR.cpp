#include "Connector.h"
#include "OR.h"

//Constructors
OR::OR(Base* lhs, Base* rhs): Connector(lhs,rhs) {}
OR::OR(): Connector() {}

//executes its right child if its left child has executed
//returns true if both children execute successfully
//otherwise returns false
bool OR::execute() {
    if(!lhs->execute()) {
        if(rhs->execute()) {
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}
