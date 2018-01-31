#include <iostream>
#include "IntVector.h"

int main()
{
    cout << "Initializing with 5, 4: " << endl;
    IntVector iv(5, 4);
    
    cout << "Size: " << iv.size() << endl;
    cout << "Capacity: " << iv.capacity() << endl;
    cout << "Empty: " << iv.empty() << endl;
    cout << "At 1: " << iv.at(1) << endl;
    cout << "Front: " << iv.front() << endl;
    cout << "Back: " << iv.back() << endl;
    cout << iv.at(4) << endl;
    iv.insert(4, iv.at(2));
    iv.erase(4);
    iv.push_back(7);
    iv.pop_back();
    iv.resize(3, iv.at(0));
    iv.resize(30, 4);
    iv.assign(12, iv.at(1));
    
    cout << endl << endl;
    
    IntVector v3(10,3);
    
    cout << "Testing insert function" << endl;
    v3.insert(1,2);
    for( unsigned i = 0; i < v3.size(); i++) 
    {
        cout << v3.at(i) << ' ';
    }
    
    cout << endl << endl;
    
    
    cout << "Testing resize function:" << endl;
    v3.resize(3);
     for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << ' ';
    }
    
    cout << endl << endl;
    
    cout << "Testing assign function:" << endl;
    v3.assign(20, 5);
 
    for(unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << " ";
    }
    
    cout << endl << endl;
    
    cout << "Initializing with 0, 0: " << endl;
    IntVector ev;
    ev.resize(20);
    ev.push_back(4);
    cout << "Size: " << ev.size() << endl;
    cout << "Capacity: " << ev.capacity() << endl;
    cout << "Empty: " << ev.empty() << endl;
    cout << "At 1: " << ev.at(1) << endl;
    cout << "Front: " << ev.front() << endl;
    cout << "Back: " << ev.back() << endl;
    cout << ev.at(4) << endl;
    ev.insert(4, ev.at(2));
    ev.erase(4);
    ev.push_back(7);
    ev.pop_back();
    ev.resize(3, ev.at(0));
    ev.resize(30, 4);
    ev.assign(12, ev.at(1));
    cout << ev.back() << "This is the back # for def constr" << endl;
    cout << "Blank size resized: " << ev.size() << endl;
    cout << "Deinitializing with ~: " << endl;
    
    return 0;
}