#include<iostream>
#include<vector>
using namespace std;
bool AllsubsetApproach_tle(int* arr,int k,int n,vector<vector<int>> sets,int idx){
   if(idx==n){
       vector<int> sum(k,0);
       for(int i=0;i<k;i++){
           if(sets[i].size()==0){
               return false;
           }
           for(int j=0;j<sets[i].size();j++){
                sum[i]=sum[i]+sets[i][j];               
           }
       }
       for(int i=1;i<k;i++){
           if(sum[i]!=sum[0]){
               return false;
           }
       }
       return true;;
   }
   for(int i=0;i<k;i++){
       sets[i].push_back(arr[idx]);
       if(AllsubsetApproach_tle(arr,k,n,sets,idx+1)==true){
           return true;
       }
       sets[i].pop_back();
   }
   return false;
}
// int issubset(vector<int> &visited,vector<int>& nums,int cur,int tar,int k,int start)
// {
//     if(k==0) return true;
//     if(cur>tar) return false;
//     if(cur==tar)
//        return issubset(visited,nums,0,tar,k-1,0);
//     for(int i=start;i<nums.size();i++)
//     {
//         if(visited[i]) continue;
//         visited[i]=1;
//         if(issubset(visited,nums,cur+nums[i],tar,k,i+1))
//             return true;
//         visited[i]=0;
//     }
//     return false;
// }
bool issubset(vector<bool> &visited,vector<int> nums,int curSum,int target,int k,int idx){
    if(k==0){
        return true;
    }
    if(curSum>target){
        return false;
    }
    if(curSum==target){
        return issubset(visited,nums,0,target,k-1,0);
    }
    for(int i=idx;i<nums.size();i++){
        if(visited[i]==true){
            continue;
        }
        else{
            visited[i]=true;
            if(issubset(visited,nums,curSum+nums[i],target,k,i+1)==true){
                return true;
            }
            visited[i]=false;
        }
    }
    return false;
}
int main(){
    int n=4;
    vector<int> nums={1,5,11,5};
    int k=2;
    vector<vector<int>> sets(k);
    int allSum=0;
    for(auto x:nums){
        allSum+=x;
    }
    if(allSum%k!=0){
        return false;
    }
    int sum=0;
    vector<bool> visited(nums.size(),0);
        for(auto it: nums)
          sum+=it;
        if(sum%k!=0)
            cout<<false;
        else
              cout<<issubset(visited,nums,0,sum/k,k,0);
}