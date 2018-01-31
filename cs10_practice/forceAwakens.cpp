#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
string sw7 = "The Force Awakens";
sw7.at(0) = 'd' + sw7.find('e');
cout << sw7 << endl;
return 0;
}