#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
   /* char letter = 'a';
    char nextLetter = 0;
    
    nextLetter = letter + 1;
    
    cout << "Letters: " << letter << " " << nextLetter << endl << " " << endl;
    
    for(int i = 0; i < 26; i++)
    {
        cout << nextLetter << endl;
        nextLetter = nextLetter + 1;
        
    }
    
    */
    
    int grade = 0;
    
    cout << "Input Grade Percentage: " << endl;
    cin >> grade;
    
    cout << "Grade: ";
    if(grade >=90)
    cout << "A" << endl;
    else if((grade >=80) && (grade<=89))
    cout << "B" << endl;
    else if((grade >=70) && (grade<=79))
    cout << "C" << endl;
    else if((grade >=60) && (grade<=69))
    cout << "D" << endl;
    else if((grade<60))
    cout << "F" << endl;
    
    return 0;
    
}