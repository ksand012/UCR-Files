#include <iostream>
#include <stdlib.h>
using namespace std;

double percentHeads(int ct)
{
    int random = 0;
    double percent = 0.0;
    srand(4444);
 
 for(int i = 0; i < ct; i++)
 {
     random = rand() % 2;
     
     if(random == 0)
     percent += 1.0;
     
 }
 
 percent /= ct;
 percent *= 100;
 
 return percent;
    
}

int main() {
   int num1 = 0;
   double num2 = 0.0;
   

    cout << "Enter the number of times you want to toss the coin: ";
    cin >> num1;
    cout << endl;
   num2 = percentHeads(num1);

   cout << "Heads came up " << num2 << "\% of the time." << endl;


   return 0;
}