#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={-1,-1,1};
    int k=0;
    unordered_map<int,int> mp;
    int prefix=0;
    int counter=0;
    
    for(int i=0;i<nums.size();i++){
        prefix+=nums[i];
        int sum=prefix+k;
        cout<<"prefix:"<<prefix<<" sum:"<<sum<<endl<<endl;
        // for(auto itr=mp.begin();itr!=mp.end();itr++){
        //     cout<<itr->first<<" "<<itr->second<<endl;
        // }
        cout<<"--"<<endl;
        if(mp.find(prefix)!=mp.end()){
            counter++;
        }
        mp[sum]++;
    }
    cout<<counter+1<<endl;
}