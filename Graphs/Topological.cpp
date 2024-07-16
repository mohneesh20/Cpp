#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void topologicalSort(int** edges,vector<bool> &visited,int n,vector<int> &sorted,int sv){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1&&visited[i]==false){
            topologicalSort(edges,visited,n,sorted,i);
        }
    }
    // cout<<sv<<" ";
    sorted.push_back(sv);
}
int main(){
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
    }
    // for(int i=0;i<n;i++){
    //     // edges[i]=new int[n];
    //     for(int j=0;j<n;j++){
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<bool> visited(n,false);
    vector<int> sorted;
    int sv;
    cin>>sv;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
        topologicalSort(edges,visited,n,sorted,i);
        }
    }
    cout<<sorted.size()<<endl;
    reverse(sorted.begin(),sorted.end());
    for(int i=0;i<sorted.size();i++){
        cout<<sorted[i]<<" ";
    }
}