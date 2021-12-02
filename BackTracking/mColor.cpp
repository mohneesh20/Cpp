#include <iostream>
#include<vector>
using namespace std;
bool isSafe(int node,vector<vector<int>> graph,vector<int> color,int col){
    for(int i=0;i<graph[node].size();i++){
        if(color[graph[node][i]]==col){
            return false;
        }
    }
    return true;
}
bool graphColor(int node,vector<vector<int>> graph,vector<int> &color,int n,int m){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(node,graph,color,i)){
            color[node]=i;
            if(graphColor(node+1,graph,color,n,m)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
int main() {
    int n,e;
    cin>>n>>e;
    int m;
    cin>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> color(n,0);
    if(graphColor(0,graph,color,n,m)){
        for(auto col:color){
        cout<<col<<" ";
        }
    }
    else{
        cout<<"cannot be coloured";
    }
}
