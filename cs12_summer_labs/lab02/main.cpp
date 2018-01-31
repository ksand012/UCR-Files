#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

int fileSum(string fn)
{
   ifstream inFS;
   inFS.open(fn.c_str());
   
   if(!inFS.is_open())
   {
      cout << "Error opening " << fn << endl;
      exit(1);
   }
   
   int add = 0;
   
   int input = 0;
   
   while(inFS >> input)
   {
      add += input;
      
   }
   
   inFS.close();
   
   
   return add;
   
   
}