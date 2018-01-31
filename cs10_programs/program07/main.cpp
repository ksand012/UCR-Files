#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;

int acquireOperands(const string &op, int &x, int &y, int &z);

int division(int a, int b, double &result);


int pythagorean(int a, int b, double &c);


int quadratic(int a, int b, int c, double &root1, double &root2);


int main()
{
    string operation;
    int number1;
    int number2;
    int number3;
    int numOperands = 0;
    int flag;
    double result; 
    double root1;
    double root2;

    cout << "Please choose an operation: ";
    cin >> operation;
    cout << endl;
    
    
    while(numOperands == 0)
    {
        if(operation == "division" || operation == "quadratic" || operation == "pythagorean")
        {
            break;
        }
        else
        {
        cout << "Error: Operation not supported." << endl;
        cout << "Please choose an operation: ";
        cin >> operation;
            
        }
        
    }


    numOperands = acquireOperands(operation, number1, number2, number3);


    if(operation == "division")
    {
        flag = division(number1, number2, result);
        cout << "Equation: " << number1 << " / " << number2 << endl;
        
        if(flag == 0)
        cout << "Result: " << result << endl;
        
        else if(flag == 1)
        cout << "Error: Cannot divide by zero." << endl;
        
    }
    else if(operation == "pythagorean")
    {
        flag = pythagorean(number1, number2, result);
        
        cout << "Equation: sqrt(" << number1 << "^2 + " << number2 << "^2 )" << endl;
        
        if(flag == 0)
        cout << "Result: " << result << endl;
    }
    else if(operation == "quadratic")
    {
        flag = quadratic(number1, number2, number3, root1, root2);
        cout << "Equation: " << number1 << "x^2 + " << number2 << "x + " << number3 << " = 0" << endl;
        if(flag == 0)
        {
            if(root1 == root2)
            cout << "Result: " << root1 << endl;
            else
            cout << "Result: " << root1 << ", " << root2 << endl;
        }
        else if(flag == 1)
        cout << "Error: Cannot divide by zero." << endl;
        
        else if(flag == 2)
        cout << "Error: Cannot take square root of a negative number." << endl;
    }

    return 0;
}

int acquireOperands(const string &op, int &x, int &y, int &z)
{
    if(op == "division" || op == "pythagorean")
    {
        cout << "Enter your first number: " << endl;
        cin >> x;
        
        cout << "Enter your second number: " << endl;
        cin >> y;
        return 2;
    }
    else if (op == "quadratic")
    {
        cout << "Enter your first number: " << endl;
        cin >> x;
        
        cout << "Enter your second number: " << endl;
        cin >> y;
        
        cout << "Enter your third number: " << endl;
        cin >> z;
        return 3;
    }
    return OK;
    
}

int division(int a, int b, double &result)
{

    if(b == 0)
    return DIV_ZERO;
    else
    {
        result = static_cast<double>(a)/b;
        return OK;
    }
    return OK;
}

int pythagorean(int a, int b, double &c)
{
    c = pow(((a*a) + (b*b)), 0.5);
    return OK;
}


int quadratic(int a, int b, int c, double &root1, double &root2)
{
    double x = ((b*b) - (4*a*c));
    
    if(a == 0)
    return DIV_ZERO;
    
    if(x < 0)
    return SQRT_ERR;
    else
    {
        root1 = (-b - sqrt(b*b - 4 * a * c))/(2*a);
        root2 = (-b + sqrt(b*b - 4 * a * c))/(2*a);
        return OK;
    }
    
}