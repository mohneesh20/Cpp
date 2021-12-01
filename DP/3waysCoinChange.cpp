#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> coins;
    coins.reserve(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        coins.push_back(tmp);
    }
    int amount;
    cin>>amount;
    vector<int> dp(n+1,0);
    dp[0]=0;
}