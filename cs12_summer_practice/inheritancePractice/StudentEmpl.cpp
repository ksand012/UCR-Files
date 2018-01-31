//StudentEmpl implementation

#include "StudentEmpl.h"

#include <iostream>
#include <iomanip>
using namespace std;

StudentEmpl::StudentEmpl(const string &name,
                         const string &addr,
                         const string &email,
                         const string &eid,
                         double hourlyRate,
                         double numHours)
 : Employee(name, addr, email, eid), 
   hourlyRate(hourlyRate), 
   numHours(numHours)
{ }

double StudentEmpl::getHourlyRate() const {
    return hourlyRate;
}

double StudentEmpl::getNumHours() const {
    return numHours;
}

void StudentEmpl::setHourlyRate(double hourlyRate) {
    this->hourlyRate = hourlyRate;
}

void StudentEmpl::setNumHours(double numHours) {
    this->numHours = numHours;
}

double StudentEmpl::paycheckAmt() const {
    return numHours * hourlyRate;
}

void StudentEmpl::display() const {
    cout << fixed << setprecision(2);

    Employee::display();
    cout << "Hourly Rate: $" << hourlyRate << endl
        << "# of Hours: " << numHours << endl;
}