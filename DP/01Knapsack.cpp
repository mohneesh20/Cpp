#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
// bool comp(vector<int> &a,vector<int> &b){
//     return true;
// }
// void recur(vector<vector<int>> &arr,int N,int W){

// }
// int mx=0;
int BruteForce(int N,int W,vector<int> &v,vector<int> &w,vector<vector<int>> &dp){
    if(N==0||W==0){
        return 0;
    }
    if(dp[N][W]!=-1){
        return dp[N][W];
    }
    if(w[N-1]<=W){
        return dp[N][W]=max(v[N-1]+BruteForce(N-1,W-w[N-1],v,w,dp),BruteForce(N-1,W,v,w,dp));
    }
    else{
        return dp[N][W]=BruteForce(N-1,W,v,w,dp);
    }
}
int main(){
    int N=3,W=4;
    // cin>>N>>W;
    vector<int> values={1,2,3};
    vector<int> weight={3,5,1};
    // vector<vector<int>> arr;
    // arr.reserve(N);  
    vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
    BruteForce(N,W,values,weight,dp);
    for(auto row:dp){
        for(auto col:row){
            cout<<col<<"  ";
        }
        cout<<endl;
    }
    // cout<<dp[N][W];
    // recur(arr,N,W);
    // sort(arr.begin(),arr.end(),comp);
    

}