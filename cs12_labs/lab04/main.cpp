#include <iostream>

using namespace std;

//Passes in an array along with the size of the array.
//Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize)
{
    double sum = 0;
    for(int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    
    sum /= arraySize;
    return sum;
}

//Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index)
{
    for(int i = index+1; i < arraySize; i++)
    {
        array[i-1] = array[i];
    }
    arraySize--;
    
    
    
}

//Passes in an array and the size of the array.
//Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << array[i];
        if(i != arraySize-1)
        cout << ", ";
    }
    return;
}

int main()
{
    int arraySize = 10;
    double array[arraySize];
    cout << "Enter 10 values:";
    for(int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }
    double meany = mean(array, arraySize);
    
    cout << endl << endl << "Mean: " << meany << endl << endl;
    
    int index = 0;
    cout << "Enter index of value to be removed: ";
    cin >> index;
    cout << endl;
    
    cout << "Before removing value: ";
    display(array, arraySize);
    cout << endl;
    remove(array, arraySize, index);
    cout << "After removing value: ";
    display(array, arraySize);
    cout << endl;
    return 0;
}