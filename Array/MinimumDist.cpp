#include<bits/stdc++.h>
using namespace std;

long long maxPoints(vector<vector<int>>& points){
    int m=points.size();
    int n=points[0].size();
    vector<vector<long long>> dp(m,vector<long long>(n,0));
    for(int i=0;i<points[n-1].size();i++){
        dp[m-1][i]=points[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=0;j<n;j++){
            long long num=INT32_MIN;
            long long sum=0;
            for(int k=0;k<n;k++){
                sum=dp[i+1][k]-abs(k-j)+points[i][j];
                num=max(num,sum);
            }
            dp[i][j]=num;
        }
    }
    long long ans=INT32_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[0][i]);
    }
    return ans;
}
int main(){
    vector<vector<int>> v={{1,2,3}};
    maxPoints(v);
}