#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={-16,9,-25,8,44,20,20,-12,11,-44,-32,7,41,13,7,27,-49,-19,-43,6};//-12 -13 -5 -7 -3 -6 11 6 5
    int m=nums.size()-1;
    while(nums[m]>0){
        m--;
    }
    int i=0;
    while(i<m){
        if(nums[i]>0){
            swap(nums[i],nums[m]);
            while(nums[m]>=0) m--;
        }
        i++;
    }
    cout<<nums.size()<<endl;
    for(auto &itr:nums){
        cout<<itr<<" ";
    }
}