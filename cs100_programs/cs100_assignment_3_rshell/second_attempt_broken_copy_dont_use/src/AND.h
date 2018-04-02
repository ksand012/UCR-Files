#ifndef __AND_H__
#define __AND_H__

#include "Connector.h"

class AND: public Connector {
    public:
    AND(Base* lefty, Base* righty);
    AND();
    virtual bool doCommand();
};
#endif
