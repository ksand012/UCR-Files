#include <iostream>
#include <string>
using namespace std;

int main() {
string firstWord = " ";
string newWord = " ";
   cout << "Enter word: ";
   cin >> firstWord;
   cout << endl << "You entered: " << firstWord << endl;
   
   for(int i = 0; i < firstWord.length(); i++)
   {
      if(firstWord.at(i) == 'a')
      newWord += "@";
      else if(firstWord.at(i) == 'e')
      newWord += "3";
      else if(firstWord.at(i) == 'i')
      newWord += "!";
      else if(firstWord.at(i) == 'g')
      newWord += "9";
      else if(firstWord.at(i) == 's')
      newWord += "$";
      else if(firstWord.at(i) == 'x')
      newWord  += "*";
      else
      newWord += firstWord.substr(i, 1);
      
   }
   
   cout << "New word:" << newWord << endl;
   
   return 0;
}