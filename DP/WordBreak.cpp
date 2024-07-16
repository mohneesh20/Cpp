#include<bits/stdc++.h>
using namespace std;
//Beats 100% of the solution
int helper(string &s,vector<string>& wordDict,vector<int>& dp,int indx){
    if(indx>s.size()) return 0;
    if(indx==s.size()) return 1;
    if(dp[indx]!=-1) return dp[indx];
    for(string &itr:wordDict){
        string word=s.substr(indx,itr.size());
        if(word==itr){
            if(helper(s,wordDict,dp,indx+itr.size())){
                return dp[indx]=1;
            }
        }
    }
    return dp[indx]=0;
}
bool wordBreak(string s,vector<string>& wordDict,vector<int>& dp){
    dp[0]=helper(s,wordDict,dp,0);
    return false;
}
int main(){

    string s="applepenappl";
    // string word=s.substr(0,20);
    vector<string> wordDict={"apple","pen"};
    vector<int> dp(s.size()+1,-1);
    wordBreak(s, wordDict,dp);
    cout<<dp[0];
    cout<<endl<<dp[s.size()];
}