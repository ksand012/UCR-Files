#include <iostream>

using namespace std;

#include "BinarySearch.h"

int main() {
   int choice = 1;
   cin >> choice;
   if (choice == 1) {         
      int arr[] = {1, 5, 8, 10, 14, 15};
      cout << bSearch(arr, 6, 1) << endl
         << bSearch(arr, 6, 0) << endl
         << bSearch(arr, 6, 15) << endl
         << bSearch(arr, 6, 14) << endl;
   } else if (choice == 2) {
      int arr2[] = {-178, -148, -99, -87, -75, -42, -23, -2};
      cout << bSearch(arr2, 8, -2) << endl
         << bSearch(arr2, 8, -178) << endl
         << bSearch(arr2, 8, -148) << endl
         << bSearch(arr2, 8, 1) << endl
         << bSearch(arr2, 8, -179) << endl
         << bSearch(arr2, 8, -1) << endl;
   } else {
      int arr3[] = {100};
      cout << bSearch(arr3, 1, 100) << endl
         << bSearch(arr3, 1, -15) << endl
         << bSearch(arr3, 1, 115) << endl;
   }

   return 0;
}