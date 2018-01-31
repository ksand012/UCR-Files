#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    if(n >= 10)
    {
        double *dptr = new double(4.5);
        int *data = new int[50];
    
    int *iptr = &n;
    
    cout << n << endl;
    cout << &n << endl;
    data[3] = 5;
    *iptr += 4;
    cout << *iptr << endl;
    delete dptr;
    delete [] data;
    }
    
    return 0;
    
    
}