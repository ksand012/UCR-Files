#include <iostream>

using namespace std;

void function(int &x)
{
    x += 10;
}

int main()
{
    int x = 0;
    x = 2;
    function(x);
    cout << x << endl;
    
}