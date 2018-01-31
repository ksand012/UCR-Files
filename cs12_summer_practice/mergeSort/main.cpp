#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int> &v, int beg, int mid, int end)
{
    vector<int> temp(end - beg+1);
    unsigned left = beg;
    unsigned right = mid+1;
    unsigned i = 0;
    while(left <= mid && right <= end)
    {
        if(v.at(left) <= v.at(right))
        {
            temp.at(i) = v.at(left);
            left++;
        }
        else
        {
            temp.at(i) = v.at(right);
            right++;
        }
        i++;
    }
    while(left <=mid)
    {
        temp.at(i) = v.at(left);
        left++;
        i++;
    }
    
    while(right <= end)
    {
        temp.at(i) = v.at(right);
        right++;
        i++;
    }
    
    for(unsigned i = 0; i < temp.size(); i++)
    {
        v.at(beg+i) = temp.at(i);
    }
    
}

void mergesort(vector<int> &v, int beg, int end)
{
    //base case
    if(beg >= end)
    return;
    
    //calculate middle of range
    int mid = (beg + end) / 2;
    
    //sort the left side
    mergesort(v, beg, mid);
    
    //sort the right side
    mergesort(v, mid+1, end);
    
    //merge 2 sorted halves
    merge(v, beg, mid, end);
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(9);
    v.push_back(7);
    v.push_back(3);
    v.push_back(9);
    v.push_back(4);
    
    for(unsigned i = 0; i < v.size(); i++)
    cout << v.at(i) << ' ';
    cout << endl;
    
    mergesort(v, 0, v.size()-1);
    
    for(unsigned i = 0; i < v.size(); i++)
    cout << v.at(i) << ' ';
    cout << endl;
}