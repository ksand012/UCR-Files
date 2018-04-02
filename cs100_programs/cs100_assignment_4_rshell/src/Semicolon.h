#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__
#include "Connector.h"

class Semicolon: public Connector {
    public:
    Semicolon(Base* lefty, Base* righty);
    Semicolon();
    virtual bool doCommand(int in, int out);
};

#endif
