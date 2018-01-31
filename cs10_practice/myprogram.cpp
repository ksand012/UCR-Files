#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age = 0; //age is initialized to zero.  does NOT equal zero.
	string name = "";
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;
	cout << "Name: " << name << "\n" << "Age: " << age << "\n";
	
	return 0;
}