#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
void helper(int n,int k,vector<bool>& v,vector<int>& temp,int idx){
    if(k==0){
        result.emplace_back(temp);
        return;
    }
    for(int i=idx;i<=n;i++){
        if(v[i]==false){
            v[i] = true;
            temp.emplace_back(i);
            helper(n,k-1,v,temp,i);
            temp.pop_back();
            v[i]=false;
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<bool> visit(n+1,false);
    vector<int> temp;
    temp.reserve(k);
    result.reserve(n*k);
    helper(n,k,visit,temp,1);
    for(auto &y:result){
        for(auto &x:y){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}