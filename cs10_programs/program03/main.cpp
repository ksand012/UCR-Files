#include <iostream>
#include <cmath>     // Note: Needed for math functions in part (3)
using namespace std;

int main() 
{
    //Initializing variables
    string player1 = "";
    string player2 = "";
    string player3 = "";
    int yard1 = 0;
    int yard2 = 0;
    int yard3 = 0;
    
    //Code begins here:
    
    cout << "Enter player 1's name: " << endl;
    cin >> player1;
    
    cout << "Enter player 1's yards gained: " << endl;
    cin >> yard1;
    
    cout << "Enter player 2's name: " << endl;
    cin >> player2;
    
    cout << "Enter player 2's yards gained: " << endl;
    cin >> yard2;
    
    cout << "Enter player 3's name: " << endl;
    cin >> player3;
    
    cout << "Enter player 3's yards gained: " << endl;
    cin >> yard3;
    
    cout << endl << "Player 1 - " << player1 << ": " << yard1 << endl;
    cout << "Player 2 - " << player2 << ": " << yard2 << endl;
    cout << "Player 3 - " << player3 << ": " << yard3 << endl;
    
    if((yard1 > yard2) && (yard1 > yard3) && (yard2 > yard3) )
    {
        cout << "1. " << player1 << ": " << yard1 << endl;
        cout << "2. " << player2 << ": " << yard2 << endl;
        cout << "3. " << player3 << ": " << yard3 << endl;
    }
    else if((yard2 > yard1) && (yard2 > yard3) && (yard1 > yard3))
    {
        cout << "1. " << player2 << ": " << yard2 << endl;
        cout << "2. " << player1 << ": " << yard1 << endl;
        cout << "3. " << player3 << ": " << yard3 << endl;
        
    }
    else if((yard3 > yard1) && (yard3 > yard2) && (yard2 > yard1))
    {
        cout << "1. " << player3 << ": " << yard3 << endl;
        cout << "2. " << player2 << ": " << yard2 << endl;
        cout << "3. " << player1 << ": " << yard1 << endl; 
        
    }
    else if((yard1 > yard2) && (yard1 > yard3) && (yard3 > yard2))
    {
        cout << "1. " << player1 << ": " << yard1 << endl;
        cout << "2. " << player3 << ": " << yard3 << endl;
        cout << "3. " << player2 << ": " << yard2 << endl; 
        
    }
    else if((yard3 > yard2) && (yard3 > yard1) && (yard1 > yard2))
    {
        cout << "1. " << player3 << ": " << yard3 << endl;
        cout << "2. " << player1 << ": " << yard1 << endl;
        cout << "3. " << player2 << ": " << yard2 << endl; 
        
    }
    else if((yard2 > yard1) && (yard2 > yard3) && (yard3 > yard1))
    {
        cout << "1. " << player2 << ": " << yard2 << endl;
        cout << "2. " << player3 << ": " << yard3 << endl;
        cout << "3. " << player1 << ": " << yard1 << endl; 
        
    }
    
}