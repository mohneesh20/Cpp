#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={1,-1};
    int k=1;
    vector<int> result;
    int mx=INT32_MIN;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++){
        mx=max(mx,nums[i]);
        mp[nums[i]]++;
    }
    result.emplace_back(mx);
    for(int i=k;i<nums.size();i++){
        mp[nums[i]]++;
        mp[nums[i-k]]--;
        if(nums[i]>mx){
            mx=nums[i];
        }else{
            if(nums[i-k]==mx){
                if(mp[nums[i-k]]==0){
                    mx=INT32_MIN;
                    for(int j=i-k+1;j<=i;j++){
                        mx=max(mx,nums[j]);
                    }
                }
            }
        }
        result.emplace_back(mx);
    }
    //return result
    for(auto &itr:result){
        cout<<itr<<" ";
    }
}