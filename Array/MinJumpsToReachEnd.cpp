#include<iostream>
#include<vector>
using namespace std;
int steps=INT32_MAX;
int minJumps(vector<int> arr, int n)
{

    // Base case: when source and
    // destination are same
    if (n == 1)
        return 0;

    // Traverse through all the points
    // reachable from arr[l]
    // Recursively, get the minimum number
    // of jumps needed to reach arr[h] from
    // these reachable points
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }

    return res;
}
int main(){
    vector<int> arr={2,1,0,3};
    cout<<minJumps(arr,arr.size());
    // MinSteps(arr,0,0,0);
    // if(steps==INT32_MAX){
    //     cout<<"NOT POSSIBLE";
    // }
    // else{
    //     cout<<steps;
    // }
}