#include "Lecturer.h"

Lecturer::Lecturer(const string &name,
    const string &addr,
    const string &email,
    const string &eid,
    double courseRate,
    double emplPerc)
 : Employee(name, addr, email, eid), courseRate(courseRate), emplPerc(emplPerc)
 {}

double Lecturer::getCourseRate() const
{
    return courseRate;
}

double Lecturer::getEmplPerc() const
{
    return emplPerc;
}

void setCourseRate(double rate)
{
    this->courseRate = rate;
}

void setEmplPerc(double perc)
{
    this->emplPerc = perc;
}

void Lecturer::display() const
{
    Employee::display();
}
