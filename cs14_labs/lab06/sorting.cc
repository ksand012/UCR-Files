#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <iomanip>

using namespace std;
template <typename T>
int partition (vector<T>& a, int l, int h)
{
    int x = a.at(h);
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (a.at(j) <= x)
        {
            i++;
            swap(a.at(i), a.at(j));
        }
    }
    swap (a.at(i + 1), a.at(h));
    return (i + 1);
}
 
/* A[] --> Array to be sorted, 
  l  --> Starting index, 
  h  --> Ending index */
template <typename T>
void quickSort(vector<T>& a, int l, int h)
{
    if (l < h)
    {        
        /* Partitioning index */
        int p = partition(a, l, h); 
        quickSort(a, l, p - 1);  
        quickSort(a, p + 1, h);
    }
}

template <typename T>
void quickSort(vector<T>& a) {
	quickSort(a, 0, a.size()-1);
}

/// Basic implementation for bubble sort with two nested loops.
/// The outer loop defines the range that is not yet sorted and the inner loop
/// passes over the unsorted range and swaps every unordered pair
/// You do not have to use the optimization heuristics that we described in class
/// but you can implement them if you would like.
template <typename T>
void bubbleSort(vector<T>& a) {
	int j = 0;
  for (int i = 0; i < a.size()-1; i++)      //hi brenda!!!

     // Last i elements are already in place   
     for (j = 0; j < a.size()-i-1; j++) 
       if (a.at(j) > a.at(j+1))
         swap(a.at(j), a.at(j+1));
}

/// In insertion sort, we start with an array of one element and then we keep
/// expanding this array element-by-element while ensuring the array is sorted
/// after adding each element
template <typename T>
void insertionSort(vector<T>& a) {
   int i, key, j;
   for (i = 1; i < a.size(); i++)
   {
       key = a.at(i);
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && a.at(j) > key)
       {
           a.at(j+1) = a.at(j);
           j = j-1;
       }
       a.at(j+1) = key;
   }
}

/// Selection sort makes n-1 passes over the array where in iteration i it selects
/// the i-th smallest element and places it in its correct position in the array.
template <typename T>
void selectionSort(vector<T>& a) {
	int temp;
for (int j = 0; j < a.size() - 1; ++j) {
    int min = a.at(j);
    temp = j;
    for (int i = j+1; i < a.size(); ++i) {
        if (min > a.at(i)) {
            min = a.at(i);  
            temp = i;
        }
    }  
    swap(a.at(j), a.at(temp));
}
}

/// Implement the original Shell sort algorithm which uses gaps of sizes
/// n/2, n/4, ..., 1
template <typename T>
void shellSort1(vector<T>& a) {
	 // Start with a big gap, then reduce the gap
    for (int gap = ((a.size())/2); gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        
        for (int i = gap; i < a.size(); i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = a.at(i);
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && a.at(j-gap) > temp; j -= gap)
                a.at(j) = a.at(j-gap);
             
            //  put temp (the original a[i]) in its correct location
            a.at(j) = temp;
        }
    }
}

/// Use Hibbard's increments for the gaps which are in the form of 2^k-1
/// Find more details on page 298 of the book
template <typename T>
void shellSort2(vector<T>& a) {
	int n = a.size();
	int i, j,k, increment, temp;
	int swp = 0;
	int comp=0;
	int val;
	val=log(n+1)/log(2);
	increment =pow(2,val)-1;
	while (increment > 0)
	{
		for (i=0;i<increment;i++)
		{
			for(j=0;j<n;j+=increment)
			{
				temp=a.at(j);
				for(k=j-increment;k>=0&&temp<a.at(k);k-=increment)
				{
					comp++;
					swp++;
					a.at(k+increment)=a.at(k);
				}
				a.at(k+increment)=temp;
				swp++;
			}
	}
	comp++;
	val--;
	if(increment!=1)
		increment=pow(2,val)-1;
	else
		increment = 0;
	}
}

/// Check whether an array is sorted or not
template <typename T>
bool isSorted(vector<T> a) {
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] > a[i+1]) {
			cout << "Elements a[" << i << "]= "<< a[i] << " and a["<<(i+1)<<"] = " << a[i+1] << " are out of order" << endl;
		  return false;
		}
	}
	return true;
}

int main() {
	// Simple test for sorting algorithms
	vector<int> values = {10, 3, 5, 7, 2, 1, 15, 13};
	vector<int> temp = values;
	bubbleSort(temp);
	EXPECT_TRUE(isSorted(temp));
	
	temp = values;
	insertionSort(temp);
	EXPECT_TRUE(isSorted(temp));

	temp = values;
	selectionSort(temp);
	EXPECT_TRUE(isSorted(temp));

	temp = values;
	shellSort1(temp);
	EXPECT_TRUE(isSorted(temp));
	
	temp = values;
	quickSort(temp);
	EXPECT_TRUE(isSorted(temp));
	
	// Measure the running time as the input size increases
	cout << right << setw(16)  << "Size"
	     << setw(16)  << "Bubble"
	     << setw(16)  << "Insertion"
	     << setw(16)  << "Selection"
	     << setw(16)  << "Shell 1"
	     //<< setw(16)  << "Shell 2"
	     << setw(16)  << "Quick" << endl;

	for (int n = 1; n <= (1<<16); n *= 2) {
		cout << setw(16) << right << n;
		values.clear();
		for (int i = 0; i < n; i++)
			values.push_back(random());
		temp = values;
		clock_t begin = clock(); // Start the stopwatch
		bubbleSort(temp);
		clock_t end = clock(); // Stop the stopwatch
    double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		insertionSort(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		selectionSort(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		temp = values;
		begin = clock();
		shellSort1(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;

		/*temp = values;
		begin = clock();
		shellSort2(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;
*/    
    	temp = values;
		begin = clock();
		quickSort(temp);
		end = clock();
		elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    cout << setw(16) << elapsed_time;
    
    cout << endl;
	}
	
	return 0;
}
