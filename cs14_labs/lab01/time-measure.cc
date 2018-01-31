#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void generate_random_numbers(vector<int>& values) {
    for (auto& x : values) {
      x = rand();
    }
}

void bubblesort(vector<int>& values) {
    int i, j;
   for (i = 0; i < values.size()-1; i++)
   {
       for(j = i; j < values.size()-i-1; j++)
       {
            if (values.at(j) > values.at(j+1))
            swap(values.at(j), values.at(j+1));
       }
   }
}

int main() {
    srand(0);
    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    for (auto size : sizes) {
      vector<int> values(size);
      generate_random_numbers(values);
      clock_t begin = clock(); // Start the stopwatch
      bubblesort(values);
      clock_t end = clock(); // Stop the stopwatch
      double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
      std::cout << "Size " << size << ": Total time " << elapsed_time << " secs" << std::endl;
    }
}


