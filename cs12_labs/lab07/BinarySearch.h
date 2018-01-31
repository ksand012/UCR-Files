#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__
#include <iostream>
using namespace std;

    int binarySearch(const int arr[], int beg, int end, int value);

    int bSearch(const int arr[], int size, int value)
    {
        return binarySearch(arr, 0, size-1, value);
    }
    
    int binarySearch(const int arr[], int beg, int end, int value)
    {
   
        if (beg <= end) 
        {
        int middle = (beg + end) / 2;
        if (value == arr[middle]) 
               return middle;
        else if (value < arr[middle]) 
               return binarySearch(arr, beg, middle-1, value);
        else
               return binarySearch(arr, middle+1, end, value);
        }
        return -1;
    }

#endif