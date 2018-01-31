#include <iostream>
#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> caseSensitive(vector<T> v) 
{
    
    // A, B,..., Z, a, b,..., z
    
    vector<T> temp;

    for(int k = 0; k < v.size(); k++) //copying array over to a temp
    {
	    temp.push_back(k);
    }

    //BUBBLE SORT BELOW
   for (int i = 0; i < v.size()-1; i++)      
 
       // Last i elements are already in place   
       for (int j = 0; j < v.size()-i-1; j++) 
           if (v.at(j) > v.at(j+1))
              swap(temp.at(j), temp.at(j+1));

    return temp;			  
}

bool caseInsensitiveHelper(char l, char r)
{
    if(l-r==32)
    return true;
    if(l-r==-32)
    return false;
    else
    {
        toupper(l);
        toupper(r);
        return l > r;
    }
}

template <typename T>
vector<T> caseInsensitive(vector<T> v) 
{
    
    // A, a, B, b,..., Z, z
    // +/- 32 int values to go from upper to lower or vice-versa ♂
    
    vector<T> temp;

    for(int k = 0; k < v.size(); k++) //copying array over to a temp
    {
	    temp.push_back(k);
    }

    //BUBBLE SORT BELOW
   for (int i = 0; i < v.size()-1; i++)      
 
       // Last i elements are already in place   
       for (int j = 0; j < v.size()-i-1; j++)
       
            // call caseInsensitiveHelper function to compare elements
           if (caseInsensitiveHelper(v.at(j), v.at(j+1)))
              swap(temp.at(j), temp.at(j+1));

    return temp;
}

int main() {
    vector<int> tinVu; //In the name of our lord, amen.
    tinVu.push_back('A'); // 0
    tinVu.push_back('C'); // 1
    tinVu.push_back('b'); // 2
    tinVu.push_back('D'); // 3
    tinVu.push_back('r'); // 4
    tinVu.push_back('s'); // 5
    tinVu.push_back('T'); // 6
    tinVu.push_back('S'); // 7
    tinVu.push_back('x'); // 8
    
    vector<int> thing = caseSensitive(tinVu);
    
    cout << "Case Sensitive: ";
    for(int j = 0; j < thing.size(); ++j) 
    {
        cout << thing.at(j) << " ";
    }
    cout << endl;
    
    vector<int> eldawy = caseInsensitive(tinVu);
    
    cout << "Case Insensitive: ";
    for(int i = 0; i < eldawy.size(); i++)
    {
        cout << eldawy.at(i) << " ";
    }
    
    cout << endl;
    
    return 0;
}