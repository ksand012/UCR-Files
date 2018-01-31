#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector<double>& nums)
{
    double userDouble = 0.0;

    cout << "Enter numbers to populate the vector ";
    cout << "(enter any other character to end user input): "; 

    while (cin >> userDouble) {
      nums.push_back(userDouble);
    }
    cout << endl;

    return;
}

double meanVector(const vector <double> &v) {

   double mean = 0.0;
   for(int i = 0; i < v.size(); i++)
   {
       mean+=v.at(i);
   }
   
   mean /= v.size();
   return mean;
}

double varianceVector(double vectorAvg, const vector <double> &v) {

   double vari = 0.0;
   
    for(int i = 0; i < v.size(); i++)
   {
       vari = vari + ((v.at(i) - vectorAvg) * (v.at(i) - vectorAvg));
   }
   return vari/(v.size());
}

double standardDeviationForVariance(double vectorVariance) {

   double v = sqrt(vectorVariance);
   return v;
}

int main() {
   vector <double> nums;
   double avg = 0.0;
   double var = 0.0;
   double stdDev = 0.0;
   unsigned int i = 0;

   fillVector(nums);

   cout << "You entered: ";
   for(int i = 0; i < nums.size(); i++)
   {
       cout << nums.at(i) << " ";
   }
   cout << endl;

   avg = meanVector(nums);
   

   var = varianceVector(avg, nums);

   stdDev = standardDeviationForVariance(var);

   cout << "The mean is: " << avg << endl;
   cout << "The variance is: " << var << endl;
   cout << "The standard deviation is: " << stdDev << endl;

   return 0;
}