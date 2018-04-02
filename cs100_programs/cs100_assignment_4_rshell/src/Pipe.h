#ifndef __PIPE_H__
#define __PIPE_H__

#include "Connector.h"

class Pipe : public Connector {
public:
	Pipe(Base* lefty, Base* righty);
	Pipe();
	virtual bool doCommand(int in, int out);
};


#endif