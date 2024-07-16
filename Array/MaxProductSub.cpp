#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums={2, 3, 4, 5, -1, 0};
    int j=1;
        int mx=INT32_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=1;
                mx=max(mx,nums[i]);
                continue;
            }
            j=j*nums[i];
            mx=max(j,mx);
        }
        j=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                j=1;
                mx=max(mx,nums[i]);
                continue;
            }
            j=j*nums[i];
            mx=max(j,mx);
        }
        return mx;
}