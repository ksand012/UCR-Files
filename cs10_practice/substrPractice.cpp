#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    string sentence = "Hello there, how are you?";
    cout << sentence << endl;
    string endphrase = " ";
    string target = ", ";
    int pos = 0;
    
    if(sentence.find(target)!= string::npos)
    {
    pos = sentence.find(target);
    endphrase = sentence.substr(pos+2, sentence.size() - 1 - (pos+ target.size()));
    }
    
    cout << endphrase << endl;
    
    return 0;
    
}