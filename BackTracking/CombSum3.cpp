#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
void CombSum2(vector<int> nums,int n,int k,vector<int> path,int idx,int sum){
    if(sum>k){
        return;
    }
    if(path.size()==n){
        if(sum==k){
            ans.push_back(path);
        }
        return;
    }
    if(idx==nums.size()){
        return;
    }
    CombSum2(nums,n,k,path,idx+1,sum);
    path.push_back(nums[idx]);
    CombSum2(nums,n,k,path,idx+1,sum+nums[idx]);
}
int main(){
    int n,k;
    cin>>n>>k;
         vector<int> nums;
        nums.reserve(9);
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        CombSum2(nums,n,k,{},0,0);
        cout<<ans.size();
        // return ans;
}