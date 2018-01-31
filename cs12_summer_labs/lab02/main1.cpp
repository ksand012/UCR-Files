#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string, char);


int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin >> ch;
   cout << endl;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

int charCnt(string fn, char ch)
{
   ifstream inFS;
   
   inFS.open(fn.c_str());
   
   if(!inFS.is_open())
   {
      cout << "Error opening " << fn << endl;
      exit(1);
   }
   
   int counter = 0;
   char input = 'a';
   
   while(inFS >> input)
   {
      if(input == ch)
      counter += 1;
      
   }
   
   inFS.close();
   
   return counter;
   
}
