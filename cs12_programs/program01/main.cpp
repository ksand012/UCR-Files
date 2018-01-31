#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main()
{
    string filename;
    vector<double> d1;
    vector<double> d2;
    char end = 'a';
    double input = 0.0;
    cout << "Enter name of input data file:" << endl;
    cin >> filename;
    cout << endl;
    
    readData(filename, d1, d2);
    
    do
    {
        cout << "Enter angle:" << endl;
        cin >> input;
        
        cout << "Coeff: " << interpolation(input, d1, d2) << endl;
        
        cout << "Go again (y/n) ?" << endl;
        
        cin >> end;
        
        
        
    }while(end != 'n');
    
    
    return 0;
}

void readData(const string& filename, vector<double>& d1, vector<double>& d2)
{
    ifstream fin(filename.c_str());
    
    if(!fin.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    
    double coef = 0.0;
    double angle = 0.0;
    
    while(fin >> angle >> coef)
    {
        d1.push_back(angle);
        d2.push_back(coef);
    }
    
    if(!isOrdered(d1))
    reorder(d1, d2);
    return;
    
}

double interpolation(double angle, const vector<double>& d1, const vector<double>& d2)
{
    
    int final = 1;
    double coefficient = 0.0;
  for(unsigned int i = 0; i < d1.size(); i++)
  {
      if(d1.at(i) == angle)
      {
          return d2.at(i);
      }
  }
  
  for(unsigned int j = 1; j < d1.size(); j++)
  {
        if((d1.at(j) > angle) && (d1.at(j-1) < angle))
        {
            final = j;
            j=d1.size();
        }
  }
 coefficient = d2.at(final - 1) + (angle  - d1.at(final - 1))/ (d1.at(final) - 
 d1.at(final - 1)) * (d2.at(final) - d2.at(final - 1)); 
    return coefficient;
  
    
}

bool isOrdered(const vector<double>& d1)
{
    for(unsigned int i = 0; i < d1.size(); i++)
    {
        if(i != d1.size() - 1)
        {
            if(d1.at(i) > d1.at(i+1))
            {
                return false;
            }
        }
    }
    return true;
}

void reorder(vector<double>& d1, vector<double>& d2)
{
    
    double temp = 0;
    for(unsigned int j = 0; j < d1.size(); j++)
    {
    for(unsigned int i = 0; i < d1.size(); i++)
    {
        if(i != d1.size()-1)
        {
            if(d1.at(i) > d1.at(i+1))
            {
                temp = d1.at(i+1);
                d1.at(i+1) = d1.at(i);
                d1.at(i) = temp;
                temp = d2.at(i+1);
                d2.at(i+1) = d2.at(i);
                d2.at(i) = temp;
                
            }
        }
    }
    
    }
    
}