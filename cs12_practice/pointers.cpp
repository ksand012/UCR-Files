#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n = 10;
    
    int *iptr = &n;
    
    cout << n << endl;
    cout << iptr << endl;
    cout << &n << endl;
    cout << *iptr << endl;
    
    double *dptr = new double;
    *dptr = 2.1;
    cout << dptr << endl;
    cout << *dptr << endl;
    
    delete dptr; //every new needs a matching delete
    
    *dptr = 45;
    
    int arr[4];
    arr[2] = 56;
    int arr2[4];
    //arr = arr2;
    arr2[2]=arr[2];
    
    char str1[80] = "Hello";
    char str2[80] = "World";
    strcpy(str1, str2);
    
    return 0;
    
}