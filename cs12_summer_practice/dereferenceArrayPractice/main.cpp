#include <iostream>

using namespace std;

int main()
{
    int g[] = {2,4,5,8,10,32,78};
    int *data = new int[7];
    for(int i = 0; i < 7; i++)
    data[i] = i*2;
    
    cout << *(g+2) << endl;
    
}