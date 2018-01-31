//interface for Student_empl type
#ifndef __STUDENT_EMPL_H__
#define __STUDENT_EMPL_H__

#include "Employee.h"

class StudentEmpl : public Employee {
 private:
    double hourlyRate;
    double numHours;
 public:
    StudentEmpl(const string &,
                const string &,
                const string &,
                const string &,
                double,
                double);
    double getHourlyRate() const;
    double getNumHours() const;
    void setHourlyRate(double);
    void setNumHours(double);
    void display() const;
    double paycheckAmt() const;
};

#endif //__STUDENT_EMPL_H__