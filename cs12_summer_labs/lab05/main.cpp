#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int &arraySize, int index);
void display(const double array[], int arraySize);

int main()
{
    int size = 10;
    double array[size];
    double input = 0.0;
    int indRem = 0;
    cout << "Enter " << size <<  " values:" << endl << endl;
    int i = 0;
    for(i = 0; i < size; i++)
    {
        cin >> input;
        array[i] = input;
    }
    
    cout << "Mean: " << mean(array, size) << endl << endl
    << "Enter index of value to be removed: ";
    cin >> indRem;
    cout << endl << "Before removing value: ";
    display(array, size);
    remove(array, size, indRem);
    cout << endl << "After removing value: ";
    display(array, size);
    cout << endl;
    
    
}

double mean(const double array[], int arraySize)
{
    double arrTotal = 0;
    int i = 0;
    for(i = 0; i < arraySize; i++)
    {
        arrTotal += array[i];
    }
    
    return arrTotal / arraySize;
}

void remove(double array[], int &arraySize, int index)
{
    int i = 0;
    
    for(i = index; i < arraySize-1; i++)
    {
        array[i] = array[i+1];
    }
    
    arraySize -=1;
    
    
}

void display(const double array[], int arraySize)
{
    int i = 0;
    for(i = 0; i < arraySize; i++)
    {
        if(i != arraySize-1)
        {
            cout << array[i] << ", ";
        }
        else
        cout << array[i];
    }
}