#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool isAscending(int arr[], int arr_size)
{
    if(arr_size < 2)
    return true;
    
    if(arr[arr_size-1] >= arr[arr_size-2])
    return isAscending(arr, arr_size-1);
    else
    return false;
}

int main()
{
    int arr[] = {3, 4, 4, 6, 7, 7, 9, 12, 12};
    
    bool dude = isAscending(arr, 9);
    
    if(dude)
    cout << "isAscending = true" << endl;
    else
    cout << "isAscending = false" << endl;
}