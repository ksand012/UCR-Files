#include "Employee.h"

Employee::Employee(const string &name,
    const string &addr,
    const string &email,
    const string &eid)
 : name(name), addr(addr), email(email), eid(eid) //initialization list
{}

const string & Employee::getName() const
{
    return name;
}

const string & Employee::getAddr() const
{
    return addr;
}

const string & Employee::getEmail() const
{
    return email;
}

void display() const
{
    
    
}