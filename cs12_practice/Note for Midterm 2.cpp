IntVector r1; //works, calls default constructor
IntVector r2(3, 4); //works, calls constructor with two int inputs
IntVector r3(r2); //works, deep copy, copies all variables, default created
IntVector r4 = r3; //works, operator overload, default created
r1 = r3; //
r3 = r3; //self assignment, dont need to do anything


Runtime Stack       Heap

r2                > 4 4 4
sz  3             |
cap 3             |
data --------------
                  |
r3                |
sz  3             |
cap 3             |
data --------------

// when working with memory allocated with new, we need a deep copy.

//stuff in runtime stack is shallow memory, sometimes has points, like fishing lines, going down to the deep memory, or deep ocean, which is heap.

//Making our own copy constructor

IntVector::IntVector(const Invector &cpy) : sz(cpy.sz), cap(cpy.cap), data(new int[cpy.cap])
{
    for(unsigned i = 0; i < sz; i++)
    {
        data[i] = cpy.data[i];
        
    }
    
}

r1 = r2 = r3;

//^reads from right to left.  r2 = r3, then r1 = r2, which is pretty much r1 = r3

IntVector IntVector::operator=(const Invector &rhs)
{
    
    if(this == &rhs)
    return *this;
    
    delete[] data;
    this->sz = rhs.sz;
    this->cap = rhs.cap;
    data = new int[this->cap];
    
    for(unsigned i = 0; i < sz; i++)
    {
        data[i] = cpy.data[i];
        
    }
    
    return *this; //return implicit
    
}

//Writing code from linked list or vector assignment

//Struct vs class: struct is all public, class is all private.  Tend to use structs when not making member functions.

//Know run-time stack and heap stuff

//For runtime stack question 8:

