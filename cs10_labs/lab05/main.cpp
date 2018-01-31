#include <iostream>
using namespace std;

int add(int n1, int n2)
{
 int sum = n1 + n2;
 return sum;
    
}

int subtract (int n1, int n2)
{
 int diff = n1 - n2;
 return diff;
    
}

int main() {
   int num1 = 0;
   int num2 = 0;
   int sum = 0; //sum of numbers
   int diff = 0; //difference of numbers

    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;
    cout << endl;

   // Call add function
   sum = add(num1, num2);

   diff = subtract(num1, num2);

    cout << endl << "First Integer: " << num1 << endl;
    cout << "Second Integer: " << num2 << endl;

   cout << endl << num1 << " + " << num2 << " = " << sum << endl;


   cout << num1 << " - " << num2 << " = " << diff << endl;


   return 0;
}