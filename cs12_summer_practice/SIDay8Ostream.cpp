#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ifstream dude("file.txt");
    string test = "";
    while(dude >> test)
    {
        cout << test << endl;
    }
    
    
}