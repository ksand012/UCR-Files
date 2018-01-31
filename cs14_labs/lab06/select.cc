#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <algorithm>
#include <random>
#include <queue>
#include <functional>

using namespace std;

void generate_random_numbers(vector<int>& values) {
    for (int i = 0; i < values.size(); i++) {
		values[i] = i * 3;
	}
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(values), std::end(values), rng);
}

template <typename T>
T select(vector<T> a, int k) {
    
    k--;
    priority_queue<T, vector<T>, greater<T> > q;
    
    //priority queue runtime of O(log n)
    
    for(int n : a) //O(n) runtime
    q.push(n);
    
    while(k > -1)
    {
        q.pop();
        k--;
    }
    
    return q.top();
    //TOTAL BIG OH RUNTIME: O((nlog(n)) + k)
    
}

template <typename T>
bool isCorrect(vector<T> a, int k, T kth) {
    int n = 0;
    for (T x : a) {
        if (x < kth)
            n++;
    }
    return n == k;
}

int main(){
    // Generate a list of random numbers
    int size = 100;
    vector<int> values(size);
    generate_random_numbers(values);
    
    // Some test values of k
    vector<int> ks = {0, 5, 20, 30};
    
    for (int k : ks) {
        int kth_value = select(values, k);
        EXPECT_TRUE(isCorrect(values, k, kth_value));
    }
    cout << "End of program" << endl;
	return 0;
}
