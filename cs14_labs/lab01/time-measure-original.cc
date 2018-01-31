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

void insertionsort(vector<int>& values) {
    // TODO: Convert the pseudo code shown in class to C++
    int key = 0;
    int j = 0;
    for (int i=1; i<values.size(); ++i) // use pre-increment to avoid unneccessary temorary object
    {
        key = values.at(i);
        j = i-1;
        while((j > 0) && (values.at(j) > key))
        {
            values.at(j+1) = values.at(j);
            j -= 1;
        }
            values.at(j+1)=key;
    }
}



int main() {
    srand(0);
    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    for (auto size : sizes) {
      vector<int> values(size);
      generate_random_numbers(values);
      int randomNum = rand();
      std::sort(values.begin(), values.end());
      clock_t begin = clock(); // Start the stopwatch
      /*for(int i = 0; i < values.size(); i++)
      {
          if(values.at(i) == randomNum)
          {
              break;
          }
      }*/
      //std::sort(values.begin(), values.end());
      //insertionsort(values);
      //generate_random_numbers(values);
      int randomNumTwo = rand();
      std::binary_search(values.begin(),values.end(), randomNumTwo);
      clock_t end = clock(); // Stop the stopwatch
      double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
      std::cout << "Size " << size << ": Total time " << elapsed_time << " secs" << std::endl;
    }
}


