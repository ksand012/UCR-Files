#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.h"
#include <cstdlib>

using namespace std;

class Connector: public Base {
    protected:
    Base* lefty;
    Base* righty;
    public:
    Connector(Base* lefty, Base* righty);
    Connector();
    virtual bool doCommand(int in, int out) = 0;
	virtual string findFunction();
};

#endif
