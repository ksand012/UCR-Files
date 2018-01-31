#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    /*int  isbn = 0;
    
    cin >> isbn;
    
    int lenIsbn = 0;
    
    int digit = 0;
    
    lenIsbn = isbn.length();
    
    digit = isbn.substr(lenIsbn, lenIsbn-1);
    
    cout << digit;
    
    */
    
    int isbn = 0;
    
    cin >> isbn;
    
    int digit = (isbn % 10) % 10;
    
    cout << digit;
    
    int reamining = isbn;
    
    int weightedSum = 0;
    
    /////////////////////////////////////
    
    for(int place = 9; place > 0; --place)
    {
        digit = remaining % 10; // grab the right-most digit
        weightedSum += place * digit; //ACCUMULATOR
        remaining = remaining / 10; //remove the right-most digitw
        
    }
    
}

