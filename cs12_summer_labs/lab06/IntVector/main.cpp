#include <iostream>
#include "IntVector.h"

using namespace std;

int main()
{
    IntVector happy;
    cout << "Happy's size is: " << happy.size() << endl;
    cout << "Happy's capacity is: " << happy.capacity() << endl;
    cout << "Is Happy empty? " << happy.empty() << endl;
    //cout << "Happy at 2: " << happy.at(2) << endl;
    //cout << "Happy at front:" << happy.front() << endl;
    //cout << "Happy at back: " << happy.back() << endl;
    cout << endl;
    
    IntVector dude(5, 2);
    cout << "Dude's size is: " << dude.size() << endl;
    cout << "Dude's capacity is: " << dude.capacity() << endl;
    cout << "Is Dude empty? " << dude.empty() << endl;
    cout << "Dude at 2: " << dude.at(2) << endl;
    cout << "Dude at front:" << dude.front() << endl;
    cout << "Dude at back: " << dude.back() << endl;
    
    
}