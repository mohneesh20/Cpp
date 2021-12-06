#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bipartiteBFS(vector<vector<int>> graph,int sv,vector<int> color){
    queue<int> q;
    color[sv]=1;
    q.push(sv);
    vector<bool> visited(graph.size(),false);
    while(q.size()!=0){
        int node=q.front();
        visited[node]=true;
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            if(color[graph[node][i]]==color[node]){
                return false;
            }
            color[graph[node][i]]=1-color[node];
            if(visited[graph[node][i]]==false){
            q.push(graph[node][i]);
            }
        }
    }
return true;
}
int main(){
    // int n,e;
    // cin>>n>>e;
    // vector<vector<int>> graph(n);
    vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
    // for(int i=0;i<e;i++){
    //     int a,b;
    //     cin>>a>>b;
    //     graph[a].push_back(b);
    //     graph[b].push_back(a);
    // }
    // for(int i=0;i<graph.size();i++){
    //     cout<<i<<":";
    //     for(auto x:graph[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> color(graph.size(),-1);
    // for(auto x:color){
    //         cout<<x<<" ";
    //     }
    if(bipartiteBFS(graph,0,color)){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
}