#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    /*int a = 932;
    int b = a%10;
    int c = a/10;
    c = c%10;
    
    cout << c;*/
    
    int now = 656;
    
    int seconds = now % 60;
    
    //cout << seconds;
    
    int minutes = (now/60) % 60;
    
   // cout << minutes;
    
    int hours = (now/(60 * 24)) % 24;
    
    cout << hours;
    
}