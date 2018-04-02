#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
protected:
    Base* root;

public:
    Command() { };
    double execute() {
        return root->evaluate();
    };
    Base* get_root() {
        return root;
    };
};

//OpCommand Code Here
class OpCommand : public Command
{
public:
    OpCommand(double num) : Command()
    {
        this->root = new Op(num);
    }
};

//AddCommand Code Here
class AddCommand : public Command
{
public:
    AddCommand(Command* first, int second) : Command()
    {
        Base* num = new Op(second);
        this->root = new Add(first->get_root(), num);
    }
    
};

//SubCommand Code Here
class SubCommand : public Command
{
public:
    SubCommand(Command* first, int second) : Command()
    {
        Base* num = new Op(second);
        this->root = new Sub(first->get_root(), num);
    }
};

//MultCommand Code Here
class MultCommand : public Command
{
public:
    MultCommand(Command* first, int second) : Command()
    {
        Base* num = new Op(second);
        this->root = new Mult(first->get_root(), num);
    }

};

//SqrCommand Code Here
class SqrCommand : public Command
{
public:
    SqrCommand(Command* first) : Command()
    {
        this->root = new Sqr(first->get_root());
    }

};

#endif //__COMMAND_CLASS__