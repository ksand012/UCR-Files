#include <iostream>

using namespace std;

/* Concatenate strings
   Appends a copy of the source string to the destination string. 
   The terminating null character in destination is overwritten by the 
   first character of source, and a null-character is included at the 
   end of the new string formed by the concatenation of both in destination.

   returns destination.
*/
char * mystrcat (char * destination, const char * source)
{
    
    int size = 0;
    char * ptr = destination;
    while(*ptr != '\0')
    {
        ++ptr;
    }
    
    size = ptr - destination;
    
    int count = 0;
    
    destination = destination + size;
    
    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        
        source++;
        
        count++;
    }
    
    *destination = '\0';
    
    destination = destination - size - count;
    
    return destination;
    
    /*
    int i = 0;
    bool found = false;
    while(!found)
    {
        if(destination[i] == '\0')
        found = true;
        else
        i++;
    }
    
    int l = 0;
    
    found = false;
    while(!found)
    {
        if(source[l] == '\0')
        found = true;
        else
        l++;
        
    }
    
    int size = i+l;
    
    int k = 0;
    for(int j = i; j < size; j++)
    {
        if(k==l)
        return destination;
        else
        {
        destination[j] = source[k];
        k++;
        }
    }
    return destination;
    */
}

int main() {
   char cstr1[80];
   char cstr2[80];

   cstr1[0] = 'L';
   cstr1[1] = 'i';
   cstr1[2] = 'o';
   cstr1[3] = 'n';
   cstr1[4] = 'e';
   cstr1[5] = 'l';
   cstr1[6] = '\0';

   cstr2[0] = 'M';
   cstr2[1] = 'e';
   cstr2[2] = 's';
   cstr2[3] = 's';
   cstr2[4] = 'i';
   cstr2[5] = '\0';

   cout << cstr1 << endl;
   cout << cstr2 << endl;

   mystrcat(cstr1, " ");
   mystrcat(cstr1, cstr2);

   cout << cstr1 << endl;

   return 0;
}