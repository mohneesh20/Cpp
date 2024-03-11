#include<bits/stdc++.h>
using namespace std;
int bin_s(vector<int>& nums,int l,int r,int target){
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==target){
            return mid;
        }else{
            if(nums[mid]>target){
                r=mid-1;
            }else l=mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int> v={-1,0,1,2,-1,-4};
    // set<int> s;
    sort(v.begin(),v.end());
    // for(auto &itr:nums){
    //     s.insert(itr);
    // }
    // vector<int> v;
    // v.reserve(s.size());
    // for(auto &itr:s){
    //     v.emplace_back(itr);
    // }
    int l=0,r=v.size()-1;
    set<vector<int>> container;
    while(l<r){
        int sum=v[l]+v[r];
        int target=0-sum;
        int ret=bin_s(v,l+1,r-1,target);
        if(ret!=-1){
            container.insert({v[l],v[ret],v[r]});
            if(sum+v[l+1]>target) r--;
            else l++;
        }else{
            if(sum+v[l+1]>target) r--;
            else l++;
        }
    }
    vector<vector<int>> result;
    for(auto &y:container){
        result.push_back(y);
    }
    // for(auto &itr:s){
    //     cout<<itr<<" ";
    // }
}