#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v(8);
    v.at(0) = 8;
    v.at(1) = 4;
    v.at(2) = 3;
    v.at(3) = 2;
    v.at(4) = 15;
    v.at(5) = 1;
    v.at(6) = 25;
    v.at(7) = 2;
    display(v);
    cout << endl;
    sort(v);
    display(v);
    cout << endl;
}

int bsearch(const vector<int>, &v)
{
    if(v.empty())
    return -1;
    bsearch(v, 0, v.size()-1, val);
}

int bsearch(const vector<int> &v, int beg, int end, int val)
{
    if(beg > end)
    return -1;
    
    int mid = (beg + end)/2;
    
    if(v.at(mid) == val)
    return mid;
    
    if(v.at(mid) < val)
    return bsearch(v, mid+1, end, val);
    
    return bsearch(v, beg, mid-1, val);
    
}