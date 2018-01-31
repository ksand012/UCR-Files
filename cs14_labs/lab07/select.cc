#include <iostream>
#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

using namespace std;

void generate_random_numbers(vector<int>& values) {
    for (int i = 0; i < values.size(); i++) {
		values[i] = i;
	}
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(values), std::end(values), rng);
}
template <typename T>
T select1(vector<T> v, int k)
{

    for(int i = 0; i <= k; ++ i){
        int min = i;
        for (int j = i+1; j < v.size(); ++ j){
            if(v.at(j) < v.at(min)){
                min = j;
            }
        }
        swap(v.at(i), v.at(min));
    }
    return v.at(k);
}

/// Sort the array and return the item at position k
template <typename T>
T select2(vector<T> v, int k) 
{
    std::stable_sort(v.begin(), v.end());
    
    return v.at(k);
}

/// Select the kth element using a heap
template <typename T>
T select3(vector<T> v, int k)
{
   priority_queue<int, vector<int>, greater<int> > minHeap;
   
    for(int i = 0; i < v.size(); i++)
    {
        minHeap.push(v.at(i));
    }
    
    for(int i = 0; i < k; i++)
    {
        minHeap.pop();
    }
    
    return minHeap.top();
}

template <typename T>
T select4(vector<T> v, int k) 
{
    int start = 0;
    int end = v.size()-1;
    int a = 0;
    
    while(start != end)
    {
        int x = v.at(end);
        int i = (start-1);
        
        for(int j = start; j <= end-1; j++)
        {
            if(v.at(j) <= x)
            {
                i++;
                swap(v.at(i), v.at(j));
            }
        }
        
    swap(v.at(i+1), v.at(end));
    
    if((i + 1) == k)
    {
        return v.at(i+1);
    }
    
    if((i + 1) < k)
    start = i + 1;
    
    if((i + 1) > k)
    end = i;
    
    }
    
    return v.at(k);
}

template <typename T>
bool isCorrect(vector<T> a, int k, T kth) 
{
    int n = 0;
    for (T x : a)
    {
        if (x < kth)
            n++;
    }
    EXPECT_EQ(k, n);
    return n == k;
}

int main(){
    // Generate a list of random numbers
    int size = 100;
    vector<int> values(size);
    // Some test values of k
    vector<int> ks = {0, 5, 20, 30};
    
    generate_random_numbers(values);

    for (int k : ks) {
        vector<int> temp = values;
        int kth_value = select1(temp, k);
        EXPECT_TRUE(isCorrect(values, k, kth_value));
        
        temp = values;
        kth_value = select2(temp, k);
        EXPECT_TRUE(isCorrect(values, k, kth_value));
        
        temp = values;
        kth_value = select3(temp, k);
        EXPECT_TRUE(isCorrect(values, k, kth_value));
        
        temp = values;
        kth_value = select4(temp, k);
        EXPECT_TRUE(isCorrect(values, k, kth_value));
    }
    
    // Measure the running times
	cout << right
	     << setw(16)  << "k"
         << setw(16)  << "Select1"
         << setw(16)  << "Select2"
         << setw(16)  << "Select3"
         << setw(16)  << "Select4" << endl;

    size = 100000;
    values.resize(size);
    ks.clear(); ks.push_back(1); ks.push_back(10); ks.push_back(100);
    ks.push_back(1000); ks.push_back(5000);
    generate_random_numbers(values);
    for (int k : ks) {
        cout << setw(16) << k;
        
        vector<int> temp = values;
        clock_t begin = clock(); // Start the stopwatch
        int kth_value = select1(temp, k);
        clock_t end = clock(); // Stop the stopwatch
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;
        
        temp = values;
        begin = clock(); // Start the stopwatch
        kth_value = select2(temp, k);
        end = clock(); // Stop the stopwatch
        elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;
        
        temp = values;
        begin = clock(); // Start the stopwatch
        kth_value = select3(temp, k);
        end = clock(); // Stop the stopwatch
        elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;

        temp = values;
        begin = clock(); // Start the stopwatch
        kth_value = select4(temp, k);
        end = clock(); // Stop the stopwatch
        elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;
        
        cout << endl;
    }
    
    cout << "-----------------" << endl;
    
    // Measure the running times
	cout << right
	     << setw(16)  << "n"
         << setw(16)  << "Select1"
         << setw(16)  << "Select2"
         << setw(16)  << "Select3"
         << setw(16)  << "Select4" << endl;

    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};
    for (int size : sizes) {
        values.resize(size);
        generate_random_numbers(values);
        cout << setw(16) << size;

        int k = 1;        
        vector<int> temp = values;
        clock_t begin = clock(); // Start the stopwatch
        int kth_value = select1(temp, k);
        clock_t end = clock(); // Stop the stopwatch
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;

        temp = values;
        begin = clock(); // Start the stopwatch
        kth_value = select2(temp, k);
        end = clock(); // Stop the stopwatch
        elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;

        temp = values;
        begin = clock(); // Start the stopwatch
        kth_value = select3(temp, k);
        end = clock(); // Stop the stopwatch
        elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;

        temp = values;
        begin = clock(); // Start the stopwatch
        kth_value = select4(temp, k);
        end = clock(); // Stop the stopwatch
        elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        cout << setw(16) << elapsed_time;
        
        cout << endl;
    }
    cout << "End of program" << endl;
	return 0;
}
