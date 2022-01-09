#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> &a,pair<int,int> &b){
    double val1=((double)a.first)/(a.second);
    double val2=((double)b.first)/(b.second);
    return val1>val2;
}
void FKnapsack(vector<pair<int,int>> eff,int W,int n){
    double bagValue=0;
    int curW=0;
    for(int i=0;i<n;i++){
        if(curW+eff[i].second<=W){
            bagValue+=eff[i].first;
            curW+=eff[i].second;
        }
        else{
            int rtWt=W-curW;
            bagValue+=(eff[i].first)*((double)rtWt/eff[i].second);
            break;
        }
    }
    cout<<bagValue;
}
int main(){
    int n=3,W=50;
    int  values[] = {60,100,120};
    int weight[] = {10,20,30};
    vector<pair<int,int>> eff;
    eff.reserve(n);
    for(int i=0;i<n;i++){
        eff.push_back(make_pair(values[i],weight[i]));
    }
    sort(eff.begin(),eff.end(),comp);
    FKnapsack(eff,W,n);
    // for(auto x:eff){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
}