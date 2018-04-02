#ifndef __BASE_H__
#define __BASE_H__

#include <string>

using namespace std;

class Base {
    public:
    virtual bool doCommand(int in, int out) = 0;
	virtual string findFunction() = 0;
};
#endif
