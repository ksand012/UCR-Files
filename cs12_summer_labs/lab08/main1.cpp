#include <iostream>
#include <string>

using namespace std;

void flipString(string &s)
{
    if(s.size()>0)
    {
        string first = s.substr(0, 1);
        string remaining = s.substr(1);
        
        flipString(remaining);
        
        s = remaining + first;
        
        
    }
    return;
    
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}