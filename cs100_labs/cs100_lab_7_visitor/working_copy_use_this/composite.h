#ifndef __COMPOSITE_CLASS__
#define __COMPOSITE_CLASS__

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "iterator.h"
#include "visitor.h"

using namespace std;

class Iterator;
class NullIterator;
class UnaryIterator;
class Visitor;
class PrintVisitor;

//Abstract Base Class
class Base {
    public:
        Base() = default;
        //virtual
        virtual void print() = 0;
        virtual double evaluate() = 0;
        virtual Iterator* create_iterator() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
		virtual void accept(Visitor* printVisitor) = 0;
};

//Leaf Class
class Op: public Base {
    private:
        double value;
    public:
        Op();
		explicit Op(double val);
        Base* get_left() override;
        Base* get_right() override;
        double evaluate() override;
        void print() override;
        Iterator* create_iterator() override;
		void accept(Visitor* printVisitor) override;
};

//Composite Base Classes
class Operator: public Base {
    protected:
        Base* left, *right;
    public:
        Operator();
        Operator(Base* l, Base* r);
        Base* get_left() override;
        Base* get_right() override;
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator() override;
};

class UnaryOperator: public Base {
    protected:
        Base* child;
    public:
        UnaryOperator();
		explicit UnaryOperator(Base* c);
        Base* get_left() override;
        Base* get_right() override;
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator() override;
};

//Composite Classes
class Add: public Operator {
    public:
        Add();
        Add(Base* left, Base* right);
        void print() override;
        double evaluate() override;
		void accept(Visitor* printVisitor) override;
};

class Sub: public Operator {
    public:
        Sub();
        Sub(Base* left, Base* right);
        void print() override;
        double evaluate() override;
		void accept(Visitor* printVisitor) override;
};

class Mult: public Operator {
    public:
        Mult();
        Mult(Base* left, Base* right);
        void print() override;
        double evaluate() override;
		void accept(Visitor* printVisitor) override;
};

class Sqr: public UnaryOperator {
    public:
        Sqr();
		explicit Sqr(Base* child);
        void print() override;
        double evaluate() override;
		void accept(Visitor* printVisitor) override;
};

class Root: public UnaryOperator {
    public:
        Root();
		explicit Root(Base* root);
        void print() override;
        double evaluate() override;
		void accept(Visitor* printVisitor) override;
};

#endif //__COMPOSITE_CLASS__
