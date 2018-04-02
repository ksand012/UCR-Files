#ifndef __OUTTWO_H__
#define __OUTTWO_H__

#include "Connector.h"

class OutTwo : public Connector {
public:
	OutTwo(Base* lefty, Base* righty);
	OutTwo();
	virtual bool doCommand(int in, int out);
};
#endif