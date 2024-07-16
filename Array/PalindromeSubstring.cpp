#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string s){
    if(s.size()==0) return 0;
    int n=s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int counter=0;
    for(int k=0;k<n;k++){
        int i=k,j=k;
        while(i>0&&j<n){
            if(i==j){
                dp[i][j]=true;
                counter++;
            }else{
                if(s[i]==s[j]&&dp[k][i+1]==true&&dp[k][j-1]==true){
                    dp[k][i]=true;
                    dp[k][j]=true;
                    counter++;
                }
            }
            i--;
            j++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return counter;
}
int main(){
    string s="aaa";
    cout<<countSubstrings(s)<<endl;
}