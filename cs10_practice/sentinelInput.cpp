#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    /*int data = 0;
    int count = 0;
    int sum = 0;
    double ave = 0.0;
    cout << "Enter #: " << endl;
    while(data >= 0)
    {
        cin >> data;
        
        if(data >= 0)
        {
            sum = sum + data;
            count++;
        }
        
    }
    ave = static_cast<double>(sum)/static_cast<double>(count);
    cout << "Avg: " << ave << endl;
    */
    
    int r = 2;
    int c = 5;
    int i = 0;
    int j = 0;
    
    for(j = 0; j < r; j++)
    {
    
    for(i = 0; i < c; i++)    
    {
        cout << "* ";
        
    }
    cout << endl;
    }
    
    return 0;
    
}