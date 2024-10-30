#include<bits/stdc++.h>
using namespace std;
class temp {
    public:
    int data;
    int freq;
    temp(int x,int y):data(x),freq(y){}
};

// Comparator to sort based on the `data` field
struct CompareData {
    bool operator()( temp*  t1, temp* t2) {
        return t1->data > t2->data;  // Min-heap based on `data`
    }
};
int smallestDistancePair(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    map<int,int> mp2;
    unordered_set<int> s;
    priority_queue<temp*, vector<temp*>, CompareData> pq;
    int cnt=0;
    for(auto &itr:nums){
        mp[itr]++;
        s.insert(itr);
    }
    vector<int> v(s.begin(),s.end());
    s.clear();
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        cnt+=itr->second-1;
    }
    mp2[0]=cnt;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            cnt=mp[v[i]]*mp[v[j]];
            int dif=abs(v[i]-v[j]);
            mp2[dif]+=cnt;
        }
    }
    for(auto itr=mp2.begin();itr!=mp2.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
        // temp* node=new temp(itr->first,itr->second);
        // pq.push(node);
    }

    // while(pq.size()!=0&&k>=0){
    //     temp* nde=pq.top();
    //     if(k<=nde->freq) return pq.top()->data;
    //     pq.pop();
    //     k-=nde->freq;
    // }
    return -1;
}


int main(){
    vector<int> v={10,6,2,10,5,4,0,1,5,2,5,5,5,0,4,9,8,6,7,9,1,10,4,8,6,3,6,2,1,7,5,0,2,6,10,10,0,3,9,0,8,3,5,9,4,4,5,2,2,7};
    int k=444;
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