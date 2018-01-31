#include <iostream>

using namespace std;

char * mystrcat (char * destination, const char * source);

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

char * mystrcat (char * destination, const char * source)
{
    /* Concatenate strings
   Appends a copy of the source string to the destination string. 
   The terminating null character in destination is overwritten by the 
   first character of source, and a null-character is included at the 
   end of the new string formed by the concatenation of both in destination.

   returns destination.
*/
    
    int index = 0;
    for(int i = 0; i < 80; i++)
    {
        if(destination[i] == '\0')
        {
            index = i;
            break;
        }
        
    }
    
    int srcCounter = 0;
    for(int j = 0; source[j] != '\0'; j++)
    {
        srcCounter++;
    }
    
    int counter = 0;
    for(int k = index; k < srcCounter+index; k++)
    {
        destination[k] = source[counter];
        counter++;
        
    }
    
    destination[index+srcCounter] = '\0';
    
    return destination;
    
}