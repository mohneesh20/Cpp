#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    // cout<<(1<<15);
    vector<int> nums={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<vector<int>> res;
    unordered_map<string,bool> mp;
    res.reserve((1<<nums.size()));
    for(int num=0;num<(1<<nums.size());num++){
        vector<int> tmp;
        string tmp_str="";
        for(int i=0;i<nums.size();i++){
            if(num&(1<<i)){
                if(tmp.size()==0||tmp[tmp.size()-1]<=nums[i]){
                tmp.push_back(nums[i]);
                tmp_str=tmp_str+to_string(nums[i]);
                }
            }
        }
        if(tmp.size()>1&&mp[tmp_str]==false){
            mp[tmp_str]=true;
            res.push_back(tmp);
        }
    }
    cout<<res.size();
    // sort(res.begin(),res.end());
    // for(int i=0;i<res.size();i++){
    //     for(int j=0;j<res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}