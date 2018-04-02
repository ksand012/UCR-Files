#ifndef __OUTONE_H__
#define __OUTONE_H__

#include "Connector.h"

class OutOne : public Connector {
public:
	OutOne(Base* lefty, Base* righty);
	OutOne();
	virtual bool doCommand(int in, int out);
};

#endif