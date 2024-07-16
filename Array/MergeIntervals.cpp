#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size()<=1){
            return intervals;
        }
        vector<vector<int>> res;
        int l=intervals[0][0];
        int r=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=r){
                r=max(intervals[i][1],r);
                if(i==intervals.size()-1){
                    res.push_back({l,r});
                }
            }
            else{
                res.push_back({l,r});
                l=intervals[i][0];
                r=intervals[i][1];
                if(i==intervals.size()-1){
                    res.push_back({l,r});
                }
            }
        }
        return res;
}
int main(){
    vector<vector<int>> arr={{10,16},{2,8},{1,6},{7,12}};
    auto ar=merge(arr);
    for(auto x:ar){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}