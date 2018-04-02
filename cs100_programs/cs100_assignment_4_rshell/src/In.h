#ifndef __IN_H__
#define __IN_H__

#include "Connector.h"

class In : public Connector {
public:
	In(Base* lefty, Base* righty);
	In();
	virtual bool doCommand(int in, int out);

};

#endif