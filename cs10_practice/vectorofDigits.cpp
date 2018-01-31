#include <iostream>
#include <vector>

using namespace std;

void displayVec(const vector<int> & v);

int main()
{
    long long n = 123456789;
    
    vector<int> digits;
    
    int i = 0;
    while(n > 0)
    {
        digits.push_backstatic_cast<char>('0' + (n%10));
        n = n/10;
        
    }
    displayVec(digits);
    cout << endl;
    
}