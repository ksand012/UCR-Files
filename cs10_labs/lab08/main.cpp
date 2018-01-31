#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double vectorMedian(vector<int>& nums)
{
  double median;
  int size = nums.size();

  if (size  % 2 == 0)
  {
      median = ((nums.at((size/2)) + nums.at((size/2)-1)))/2.0;
  }
  else 
  {
      median = nums.at(size/2);
  }

  return median;  
    
}

int main()
{
    vector<int> v;
    double median = 0.0;
    
    median = vectorMedian(v);
    
    cout << "The median is: " << median << endl;
    return 0;
}