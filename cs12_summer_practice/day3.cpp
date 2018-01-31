#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream fin; //initializes the file input stream object
    fin.open("testData.dat"); //allows us to connect this stream to a file
    
    if(!fin.is_open())
    {
        cout << "It's not working." << endl;
        exit(0); //ends entire program
    }
    
    if(fin.is_open())
    cout << "It's working!" << endl;
    
    int n = 0;
    while(fin >> n) //USE THIS, DO NOT USE while(!fin.eof()) BECAUSE REPEATS LAST DIGIT!!!!!!!!111!!!!
    {
        cout << n << endl;
    }
    /*string word = "";
    while(getline(fin, word))
    {
        cout << word << ' ';
    }
    cout << endl;*/
    
    fin.close();
    
    //to open a string filename
    //example: fin.open(filename)
    //you gotta do fin.open(filename.c_str())
    //or just compile g++ -std=c++11 class.cpp
    
    return 0;
    
}