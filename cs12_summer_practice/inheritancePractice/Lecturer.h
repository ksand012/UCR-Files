#ifndef __LECTURER_H__
#define __LECTURER_H__

#include "Employee.h"

class Lecturer : public Employee
{
    private:
    double courseRate;
    double emplPerc;
    public:
    Lecturer(const string &, const string &, const string &, const string &, double, double);
    double getCourseRate() const;
    double getEmplPerc() const;
    void setCourseRate(double);
    void setEmplPerc(double);
    void display() const;
    
    
};

#endif