#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void readData(const string& filename, vector<double>& flight, vector<double>& col);


double interpolation(double b, const vector<double>& flight, const vector<double>& col);


bool isOrdered(const vector<double>& flight);


void reorder(vector<double>& flight, vector<double>& col);


unsigned minLoc(const vector<double>& flight, const vector<double>& col, unsigned start);

bool isInside(const double& angle, const vector<double>& flight);


int main()
{
    string filename;
    double angle = 0.0;
    vector<double> flight;
    vector<double> col;
    string response = "";
    cout << "Enter name of input data file:" << endl;
    cin >> filename;
    cout << endl;
    readData(filename, flight, col);
    
    do
    {
        cout << "Flight path angle?" << endl;
        cin >> angle;
    
        if(!isOrdered(flight))
        reorder(flight, col);
    
        while(!isInside(angle, flight))
        {
            cout << "Angle is out of bounds of the data set.  Please try another angle: " << endl;
            cin >> angle;
            if(!isOrdered(flight))
            reorder(flight, col);
        
        }
    
        
            double var = interpolation(angle, flight, col);
        
            cout << "Output angle: " << var << endl;
            
        cout << "Enter another flight-path angle?(yes/no)" << endl;
        cin >> response;
    
    
    
    
    }while(response != "no");
}

void readData(const string& filename, vector<double>& flight, vector<double>& col)
{
    ifstream ifSS(filename);
    
    if(!ifSS.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    double tempData = 0.0;
    
    while(ifSS >> tempData)
    {
        flight.push_back(tempData);
        
        ifSS >> tempData;
        
        col.push_back(tempData);
    }
    
    
}

double interpolation(double b, const vector<double>& flight, const vector<double>& col)
{
    //f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
    double a = 0.0;
    int aLoc = 0;
    double c = 0.0;
    int cLoc = 0;
    for(unsigned i = 0; i < flight.size()-1; i++)
    {
        
        if(flight.at(i) == b)
        {
            return col.at(i);
        }
        
        else if(flight.at(i+1) == b)
        {
            return col.at(i+1);
        }
        
        else if((flight.at(i) < b) && (flight.at(i+1) > b))
        {
            a = flight.at(i);
            aLoc = i;
            c = flight.at(i+1);
            cLoc = i+1;
        }
    }
    
    return col.at(aLoc) + ((b-a)/(c-a))*(col.at(cLoc)-col.at(aLoc));
    
    
    
}

bool isOrdered(const vector<double>& flight)
{
    
    if(flight.size() < 1)
    return true;
    
    for(unsigned i = 0; i < flight.size()-1; i++)
    {
        if(flight.at(i) > flight.at(i+1))
        return false;
        
    }
    
    return true;
}

void reorder(vector<double>& flight, vector<double>& col)
{
    unsigned jVar = 0;
    for(unsigned i = 0; i < flight.size(); i++)
    {
        jVar = minLoc(flight, col, i);
        swap(flight.at(i), flight.at(jVar));
        swap(col.at(i), col.at(jVar));
        
    }
}

unsigned minLoc(const vector<double>& flight, const vector<double>& col, unsigned start)
{
    unsigned minL = start;
    
    for(unsigned j = start + 1; j < flight.size(); j++)
    {
        if(flight.at(j) < flight.at(minL))
        {
            minL = j;
        }
        
    }
    
    return minL;
    
}

bool isInside(const double& angle, const vector<double>& flight)
{
    double min = 0.0;
    double max = 0.0;
    for(unsigned i = 0; i < flight.size(); i++)
    {
        if(flight.at(i) < min)
        min = flight.at(i);
        else if(flight.at(i) > max)
        max = flight.at(i);
    }
    
    if((angle >= min) && (angle <= max))
    return true;
    else
    return false;
    
}