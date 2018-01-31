#include <iostream>
#include <vector>
#include <iomanip>
#include "Employee.h"
#include "Lecturer.h"
#include "StudentEmpl.h"

using namespace std;

int main() {
    
    // Employee emp1 = Employee("Charles Babbage",
    //                          "1791 Programmer Dr.",
    //                          "cbabb010@ucr.edu",
    //                          "110100101");
    
    Lecturer lec1 = Lecturer("Kris Miller", 
                             "999 Main St.", 
                             "kmiller@cs.ucr.edu", 
                             "123456789",
                             5983.25,
                             0.6667);
 
    Lecturer lec2 = Lecturer("Jane Doe",
                             "123 Silver Lane",
                             "jdoe001@ucr.edu",
                             "861913456",
                             6457.0,
                             1.0);


    StudentEmpl stu1 = StudentEmpl("Ada Lovelace",
                                  "1979 Babbage Lane",
                                  "alove012@ucr.edu",
                                  "0010121815",
                                  10.5,
                                  38.75);

    StudentEmpl stu2 = StudentEmpl("Alan Turing",
                                  "1001 Boolean Dr.",
                                  "aturi001@ucr.edu",
                                  "101100011",
                                  22.0,
                                  55.5);


    
    vector<Employee *> employees;
    // employees.push_back(&emp1);
    employees.push_back(&lec1);
    employees.push_back(&lec2);
    employees.push_back(&stu1);
    employees.push_back(&stu2);
    
    
    //display employees 
    
    for (unsigned i = 0; i < employees.size(); ++i) {
        employees.at(i)->display(); cout << endl;
    }
    
    // emp1.display();
    // cout << endl;
    // lec1.display();
    // cout << endl;
    // lec2.display();
    // cout << endl;
    // stu1.display();
    // cout << endl;
    // stu2.display();
    // cout << endl;
    
  
    // calculate & output total monthly payroll
    double totPayout = 0;
    for (unsigned i = 0; i < employees.size(); ++i) {
        totPayout += employees.at(i)->paycheckAmt();
    }
    cout << "Total Payout this payperiod: $" << totPayout << endl;
    

  return 0;
}