#include<bits/stdc++.h>
using namespace std;
void longestSubarray(vector<int>& nums,int limit){
    int i=0,j=0;
    int ans=0;
    int mx=INT32_MIN,mn=INT32_MAX;
    unordered_map<int,int> mp;
    while(j!=nums.size()){
        mx=max(mx,nums[j]);
        mn=min(mn,nums[j]);
        if(abs(nums[j]-nums[i])<=limit){
            mp[nums[j]]++;
            ans=max(ans,j-i);
            j++;
        }else{
            mp[nums[i]]--;
            if((nums[i]==mx||nums[i]==mn)&&mp[nums[i]]==0){
                for(int k=i;k<=j;k++){
                    mx=max(mx,nums[k]);
                    mn=min(mn,nums[k]);
                }
            }
            i++;
        }
    }
    cout<<ans;
}
int main(){
    vector<int> nums={8,2,4,7};
    int limit=4;
    longestSubarray(nums,limit);
}