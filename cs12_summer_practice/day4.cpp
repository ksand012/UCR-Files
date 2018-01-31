#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

string int2str(int n)
{
    ostringstream ssout;
    ssout << n;
    string s = ssout.str();
    return s;
    
}

int string2int(string s)
{
    istringstream ssin(s);
    int e = 0;
    ssin >> e;
    return e;
    
}


int main(int argc, char* argv[])
{
    string silly = "1479";
    int dude = string2int(silly);
    cout << dude;
    
    if(argc < 2)
    {
        cout << "Usage: " << argv[0] << " filename" << endl;
        return 1;
        
        
    }
    ifstream fin(argv[1]);
    if(!fin.is_open())
    {
        cout << "Error opening " << argv[1] << endl;
        return 1;
    }
    
    //to open a string filename
    //example: fin.open(filename)
    //you gotta do fin.open(filename.c_str())
    //or just compile g++ -std=c++11 class.cpp
    
    return 0;
    
}