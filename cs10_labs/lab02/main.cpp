#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    double xCoord1 = 0.0;
    double yCoord1 = 0.0;
    double xCoord2 = 0.0;
    double yCoord2 = 0.0;
    double calc = 0.0;
    
    cout << "Enter X Coordinate 1" << endl;
    cin >> xCoord1;
    cout << "Enter Y Coordinate 1" << endl;
    cin >> yCoord1;
    
    cout << "Enter X Coordinate 2" << endl;
    cin >> xCoord2;
    cout << "Enter Y Coordinate 2" << endl;
    cin >> yCoord2;
    
    calc = sqrt(pow((xCoord2 - xCoord1), 2.0) + pow((yCoord2 - yCoord1), 2.0));
    
    cout << "Distance between (" << xCoord1 << ", " << yCoord1 << ") and (" << xCoord2 << ", " << yCoord2 << "): " << calc << endl;
    
    return 0;
}