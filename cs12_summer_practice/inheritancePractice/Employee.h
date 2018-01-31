#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>

using namespace std;

class Employee{
    private:
    string name;
    string addr;
    string email;
    string eid;
    public:
    Employee::Employee(const string &name, const string &addr, const string &email, const string &eid);

const string & Employee::getName() const;

const string & Employee::getAddr() const;

const string & Employee::getEmail() const;

void display() const;
    
};

#endif