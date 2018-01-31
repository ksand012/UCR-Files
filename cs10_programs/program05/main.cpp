#include <iostream>
using namespace std;

int main() {
   
   int rowChar = 0;
   int numRows = 0;
   int leavesCol = 0;
   cout << "Enter trunk height: ";
   cin >> rowChar;
   cout << "Enter trunk width: ";
   cin >> numRows;
   while(numRows % 2 == 0)
   {
    cout << "Please enter an odd number for the width: ";
    cin >> numRows;
   }
   cout << "Enter leaves width: ";
   cin >> leavesCol;
   cout << endl;
   
   
   for(int i = 1; i <= leavesCol; i++)
   {
      for(int j = 0; j < ((leavesCol - i)/2); j++)
      {
       cout << " ";  
      }
      for(int k = 0; k < i; k++)
      {
       cout << "*";  
      }
      cout << endl;
      if(i%2 !=0)
      i=i+1;
   }
   
    int l = 0;
    int j = 0;
    //int m = 0;
    int n = leavesCol - numRows;
    int o = 0;
    
    for(j = 0; j < rowChar; j++)
    {
    for(o = 0; o < (n/2); o++)
    {
        cout << " ";
    
    }
    for(l = 0; l < numRows; l++)    
    {
        cout << "*";
        
    }
    cout << endl;
    }
   
   return 0;
}