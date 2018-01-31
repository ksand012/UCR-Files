#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    if(s.size()<=1)
    return true;
    
    if(s.at(0) != s.at(s.size()-1))
    return false;

    return isPalindrome(s.substr(1, s.size()-2));
    
    
}

int main()
{
    string input = "";
    cout << "Enter word: " << endl;
    cin >> input;
    cout << endl;
    bool n = isPalindrome(input);

    if(n)
    cout << "Is a palindrome." << endl;
    else
    cout << "Is not a palindrome." << endl;
    
}

//Reverse linked list recursively for final

/*

int f(IntNode * n)
{
    if(n == 0)
    return 0;
    
    return n->data + f(n->next);
    
    
}

int main()
{
    int sum = f(p->head);
    
    
}

int count(IntNode * n)
{
    if(n==0)
    return 0;
    return 1+count(n->data);
}

*/