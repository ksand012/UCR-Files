#ifndef __TREE_H__
#define __TREE_H__

#include <string>
#include "Base.h"

class Tree{
public:
	Tree(char* p);
	Tree();
	void splitUpFirstCharacter(char* p);
	void splitUpLastCharacter(char* p);
	void splitUpLastCharacterAlways(char *p);
	bool checkCon(char *q);
	bool checkAllCon(char *q);
	Base* grabTree(char *cstr);
	std::string SepCommands(char *q);
};
#endif