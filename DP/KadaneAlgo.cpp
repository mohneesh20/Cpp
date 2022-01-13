#include<iostream>
#include<vector>
using namespace std;
int maxSubArraySum(vector<int> a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main(){
    vector<int> arr={1,2,3,42,3,-1};
    cout<<maxSubArraySum(arr,arr.size());
   
}