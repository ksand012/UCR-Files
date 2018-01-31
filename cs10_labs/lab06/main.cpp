#include <iostream>
using namespace std;

void multiply(double n1, double n2, double& prod)
{
    prod = n1 * n2;
    return;
    
}
void divide(double n1, double n2, double& quot)
{
    quot = n1/n2;
    return;
    
}

int main() {
   double num1 = 0.0;
   double num2 = 0.0;
   double prod = 0.0; //product of numbers
   double quot = 0.0; //quotient of numbers

   cout << "Enter the first floating point number: ";
   cin >> num1;
   cout << endl;
   cout << "Enter the second floating point number: ";
   cin >> num2;
   cout << endl << endl;
   cout << "First floating point number: " << num1 << endl;
   cout << "Second floating point number: " << num2 << endl << endl;

   //Call multiply function
   multiply(num1, num2, prod);

   divide(num1, num2, quot);


   cout << num1 << " * " << num2 << " = " << prod << endl;


   cout << num1 << " / " << num2 << " = " << quot << endl;


   return 0;
}