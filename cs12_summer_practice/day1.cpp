#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(333);
    
    int small = 3;
    int large = 8;
    
    cout << small + rand() % (large - small + 1) << endl;
    
    return 0;
    
}