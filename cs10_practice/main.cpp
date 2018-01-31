#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    float students = 0.0;
    float classes = 0.0;
    float avg = 0.0;
    
    cout << "How many students?" << endl;
    cin >> students;
    
    cout << "How many classes?" << endl;
    cin >> classes;
    
    avg = (students/classes);
    
    cout << "The average students per class is: " << avg << endl;
    
    /*
    
    Correct code below:
    int numStudents = 0;
    int numClasses = 0;
    double avgStperClass = 0.0;
    
    cout << "How many students?" << endl;
    cin >> numStudents;
    
    cout << "How many classes?" << endl;
    cin >> numClasses;
    
    avgStperClass = static_cast<double>(numStudents) / static_cast<double>(numClasses);
    
     cout << "The average students per class is: " << avgStperClass << endl;
    
    
    */
}