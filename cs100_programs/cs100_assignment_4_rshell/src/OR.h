#ifndef __OR_H__
#define __OR_H__

#include "Connector.h"

class OR: public Connector {
    public:
    OR(Base* lefty, Base* righty);
    OR();
    virtual bool doCommand(int in, int out);
};

#endif
