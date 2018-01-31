#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string fileName);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string fileName) {
   ifstream inputFile;
   
   inputFile.open(fileName.c_str());
   int n;
   int sum = 0;
   
      if(!inputFile.is_open()) {
         cout << "Error opening " << fileName << endl;
         exit(1);
      }
      
      while(inputFile >> n) {//!inputFile.eof()){
          
            sum += n;
         }
         
         inputFile.close();
         
   return sum;
}