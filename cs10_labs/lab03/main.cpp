#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string input = "";
    string lol = "LOL";
    string idk = "IDK";
    string bff = "BFF";
    string imho = "IMHO";
    string tmi = "TMI";
    
    cout << "Input an abbreviation: " << endl;
    cin >> input;
    
    if(input== lol)
        cout << "laughing out loud" << endl;
    else if(input == idk)
        cout << "I don't know" << endl;
    else if(input == bff)
        cout << "best friends forever" << endl;
    else if(input == imho)
        cout << "in my humble opinion" << endl;
    else if(input == tmi)
        cout << "Too much information" << endl;
    else
        cout << "Unknown" << endl;
        
    return 0;
}