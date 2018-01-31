#include <iostream>
#include <string>
using namespace std;

int main() {
string firstWord = " ";
string newWord = " ";
   cout << "Enter text: ";
   getline(cin, firstWord);
   cout << endl << "You entered: " << firstWord << endl;
      while(firstWord.find("BFF") != string::npos)
      firstWord.replace(firstWord.find("BFF"), 3,  "best friend forever");
      while(firstWord.find("IDK") != string::npos)
      firstWord.replace(firstWord.find("IDK"), 3, "I don't know");
      while(firstWord.find("JK") != string::npos)
      firstWord.replace(firstWord.find("JK"), 2, "just kidding");
      while(firstWord.find("TMI") != string::npos)
      firstWord.replace(firstWord.find("TMI"), 3, "too much information");
      while(firstWord.find("TTYL") != string::npos)
      firstWord.replace(firstWord.find("TTYL"), 4, "talk to you later");
      
      cout << "Expanded: " << firstWord << endl;
   
   return 0;
}