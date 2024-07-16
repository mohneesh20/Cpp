#include<bits/stdc++.h>
using namespace std;
void geCon(vector<vector<int>> edges){
    int n=edges.size()+1;
    vector<int> par(n,0);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
           if(edges[i][j]==1){
                for(int k=1;k<par.size();k++){
                    if(par[k]==par[j]){
                        par[k]=par[i];
                    }
                }
           }
        }
    }
    for(auto itr:par){
        cout<<itr<<" ";
    }
}
int main(){
    vector<vector<int>> edges={{1,1,0},{1,1,0},{0,0,1}};
    geCon(edges);
}