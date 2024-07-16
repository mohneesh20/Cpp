#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n;
    cin>>n;
    vector<int> start={3,0,5,8,5,1};
    vector<int> end={4,6,7,9,9,2};
    vector<pair<int,int>> activity;
    activity.reserve(n);
    for(int i=0;i<n;i++){
        activity.push_back(make_pair(end[i],start[i]));
    }
    // for(int i=0;i<n;i++){
    //     cout<<activity[i].first<<' '<<activity[i].second<<endl;
    // }
    sort(activity.begin(),activity.end(),comp);
    // for(int i=0;i<n;i++){
    //     cout<<activity[i].first<<' '<<activity[i].second<<endl;
    // }
    int prev=0;
    for(int i=0;i<n;i++){
        if(activity[i].second>prev){
            cout<<activity[i].first<<" "<<activity[i].second<<endl;
            prev=activity[i].first;
        }
    }
}