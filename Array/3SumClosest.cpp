#include<bits/stdc++.h>
using namespace std;


void threeSumClosest(vector<int>& nums,int target){
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1,k=i+1;
    int mnDif=INT32_MAX;
    int ans=-1;
    while(i<j){
        j=nums.size()-1;
        k=i+1;
        int prev=nums[i];
        while(k<j){
            int sum=nums[i]+nums[k]+nums[j];
            int diff=target-sum;
            if(diff==0) return;
            if(mnDif>diff){
                ans=sum;
                mnDif=diff;
            }
            if(diff>0){
                int prev2=nums[k];
                while(k<j&&nums[k]==prev2) k++;
            }else{
                int prev2=nums[j];
                while(k<j&&nums[j]==prev2) j--;
            }
            cout<<nums[i]<<" "<<nums[k]<<" "<<nums[j]<<":"<<sum<<":"<<diff<<"="<<ans<<endl;
        }
        while(i<j&&nums[i]==prev) i++;
    }
}

int main(){
    vector<int> nums={-1,2,1,-4};
    int target=1;
    threeSumClosest(nums,target);
}