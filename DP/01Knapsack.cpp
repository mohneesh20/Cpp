#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b){
    return a.second>=b.second;
}
void Knapsack(vector<pair<int,int>> atr,int maxWeight){
int bag=0,value=0;
    if(bag>=maxWeight){
        return;
    }
    for(auto x:atr){
        cout<<x.first<<' '<<x.second<<endl;
    }
    // Knapsack(atr,W,i)   
}
int main(){
    int N,W;
    cout<<"Enter number of items:";
    cin>>N;
    vector<pair<int,int>> atr;
    atr.reserve(N);
    for(int i=0;i<N;i++){
        int wt,val;
        cin>>wt>>val;
        atr.push_back(make_pair(wt,val));
    }
    cout<<"Enter max weight:";
    cin>>W;
    // sort(atr.begin(),atr.end(),comp);
    Knapsack(atr,W);
}