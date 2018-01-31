#include <iostream>
using namespace std;

int BinarySearch(int arr[], int beg, int end, int value) {
   
   if (beg <= end) {
       int middle = (beg + end) / 2;
       if (value == arr[middle]) 
           return middle;
       else if (value < arr[middle]) 
           return BinarySearch(arr, beg, middle-1, value);
       else
           return BinarySearch(arr, middle+1, end, value);
   }
   return -1;
}

int main()
{
    const int SIZE = 4;
    int arr[SIZE] = {0};
    int input = 0;
    
    for(unsigned i = 0; i < SIZE; i++)
    {
        cout << "Enter #" << i+1 << ": ";
        cin >> input;
        cout << endl;
        arr[i] = input;
    }
    
    //sort it just in case
    for(unsigned i = 0; i < SIZE; i++)
    {

        int min = arr[i];

        for (unsigned j = i+1; j < SIZE; j++)
        {

            if( arr[j] < min )
            {
                min = arr[j];

                int tmp = arr[i];
                arr[i]    = arr[j];
                arr[j]    = tmp;
            }
        }
    }
    cout << "Your array has been sorted from least to greatest.  The array is now seen as this: ";
    cout << endl << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl << endl;
    
    cout << "Please enter a value you are looking for: ";
    cin >> input;
    cout << endl;
    
    int final = BinarySearch(arr, 0, SIZE-1, input);
    if(final == -1)
    cout << "The BinarySearch function failed to return anything." << endl;
    else
    cout << "The BinarySearch function returned the index of " << final << " and found the value of " << input << " in it." << endl;
    
    cout << endl;
}