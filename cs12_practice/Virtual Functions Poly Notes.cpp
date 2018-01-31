virtual function:
- causes dynamic binding

dynamic binding:
- at runtime bind the function according to the type of the object being pointed to rather than the type of the pointer

static binding:
- at compile time bind the function according to the type of the pointer

virtual double paycheckAmt() const = 0; <---- pure virtual.  not required to implement the function

pure virtual turns it into an abstract base class.  not an actual physical thing.  by making one of its classes virtual, employee 


pure virtual function: (add "=0" to end of virtual function declaration)
- not necessary to implement function for base class
- derived class MUST override
- class now abstract base class

abstract base class:
- if at least one function is pure virtual
- cannot instantiate an object of this type (can only derive from it)