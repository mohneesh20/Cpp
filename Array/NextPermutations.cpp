#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={1,3,2};
    int j=nums.size()-2;
    while(j>=0&&nums[j]>=nums[j+1]) j--;
    if(j<0){
        sort(nums.begin(),nums.end());
        for(auto &itr:nums){
        cout<<itr<<" ";
        }
        return 0;
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]>nums[j]){
            swap(nums[i],nums[j]);
            break;
        }
    }
    j++;
    int i=nums.size()-1;
    while(j<i){
        swap(nums[i],nums[j]);
        j++;
        i--;
    }
    for(auto &itr:nums){
        cout<<itr<<" ";
    }

}