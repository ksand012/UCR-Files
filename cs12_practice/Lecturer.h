#ifndef _LECTURER_H_
#define _LECTURER_H_

Lecturer::Lecturer(const string &name, const string &addr, const string &email, const string &eid, double courseRate, double emplPerc)
{
    : Employee(name, addr, email, eid), courseRate(courseRate), emplPerc(emplPerc)
    
}