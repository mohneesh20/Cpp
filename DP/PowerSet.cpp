#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
void permutauions(vector<int>& nums){
    int n=nums.size();
    int total=(1<<n);
    vector<vector<int>> result;
    result.reserve(total);
   for(int number=0;number<total;number++){
       vector<int> temp;
       for(int i=0;i<nums.size();i++){
            if(number&(1<<i)){
                temp.emplace_back(nums[i]);
            }
       }
       result.emplace_back(temp);
   }
   for(auto& v : result){
        for(auto& v2 : v){
            cout<<v2<<" ";
        }
    cout<<endl;
   }

}
int main(){
    vector<int> nums={1,2,3};
    permutauions(nums);
}