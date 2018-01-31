#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const char *mystrchr(const char * str, char ch)
{
    int i = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
        return * str + i;
    }
    return 0;
}

int main()
{
    char str1[80] = "Apple";
    char str2[80] = "Banana";
    
    return 0;
}