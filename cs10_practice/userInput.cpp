#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    string word = "proton";
    char target = 'p';
    int foundIndex = -1;
    bool isFound = false;
    
    int i = 0;
    
    for(i = 0; i < word.size(); i++)
    {
       if(word.at(i) == target)
       {
               foundIndex = i;
               isFound = true;
               i = word.size();
               //break;
       }
       
        
    }
    cout << "Found Index: " << foundIndex << endl << "Is Found: " << isFound << endl;
 
 return 0;   
}