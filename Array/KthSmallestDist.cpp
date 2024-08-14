#include<bits/stdc++.h>
using namespace std;

int smallestDistancePair(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    map<int,int> mp2;
    unordered_set<int> s;
    int cnt=0;
    for(auto &itr:nums){
        mp[itr]++;
        if(mp[itr]>1) cnt++;
        s.insert(itr);
    }
    vector<int> v(s.begin(),s.end());
    s.clear();
    mp2[0]=cnt;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            cnt=mp[v[i]]*mp[v[j]];
            int dif=abs(v[i]-v[j]);
            mp2[dif]+=cnt;
        }
    }
    for(auto itr=mp2.begin();itr!=mp2.end();itr++){
        cout<<itr->first<<":"<<itr->second<<endl;
    }
    int ans=-1;
}


int main(){
    vector<int> v={9,10,7,10,6,1,5,4,9,8};
    int k=18;
    sort(v.begin(),v.end());
    map<int,int> mp;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
           mp[abs(v[i]-v[j])]++;
        }
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    cout<<"-------"<<endl;
    smallestDistancePair(v,k);
}