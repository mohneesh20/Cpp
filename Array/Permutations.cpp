#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
void permute(vector<int> &nums,int idx){
    if(idx==nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        permute(nums,idx+1);
        swap(nums[idx],nums[i]);
    }
}
int main(){
    vector<int> arr={1,3,2,4};
    permute(arr,0);
    sort(result.begin(),result.end());
    int counter=1;
    for(auto &y:result){
        string str="";
        for(auto &x:y){
            str+=to_string(x);
        }
        cout<<counter++<<":"<<str;
        cout<<endl;
    }
}