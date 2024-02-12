#include<bits/stdc++.h>
using namespace std;
//13 -33 -25 45 -16 -43 -17 37 
//-33 -25 -16 -43 -17 12 45 37
vector<int> rearrange(vector<int> arr,int n){
    int j = 0; // Keeps track of the position where the next negative number should be placed

    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (i != j) {
                // Swap arr[i] with arr[j]
                int temp = arr[i];
                for (int k = i; k > j; --k) {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
            }
            ++j; // Move to the next position where the next negative number should be placed
        }
    }
    return arr;
}
int main(){
    vector<int> nums={-12, 11, -13, -5, 6, -7, 5, -3, -6};//-12 -13 -5 -7 -3 -6 11 6 5
    int m=nums.size()-1;
    vector<int> nums2=rearrange(nums,m+1);
    //Without Maintaing Order
    // while(nums[m]>0){
    //     m--;
    // }
    // int i=0;
    // while(i<m){
    //     if(nums[i]>0){
    //         swap(nums[i],nums[m]);
    //         while(nums[m]>=0) m--;
    //     }
    //     i++;
    // }
    // cout<<nums.size()<<endl;
    for(auto &itr:nums2){
        cout<<itr<<" ";
    }
}