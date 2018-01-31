#include <iostream>
#include <vector>
using namespace std;

/*******************************************************************
@params: int, number who's primeness is to be tested
@return: bool, true if prime
@precondition: num > 1
@postcondition: return value will be true if passed in prime number
********************************************************************/
bool isPrime(int num)
{
    for (int i=2; i<num; i++)
	{
		if (num % i == 0)
		{
		    cout << "DEBUG: " << i << " did it." << endl;
			return false;
		}
	}
    return true;
    
}

int main()
{
    int num = 0;
    cout << "Enter # to determine if prime: " << endl;
    cin >> num;
    bool prime = isPrime(num);
    if(prime)
        cout << num << " IS prime." << endl;
    else
    cout << num << " is NOT prime." << endl;
    return 0;
}