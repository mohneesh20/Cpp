#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
/*
10 6
1 3
4 2
5 7
7 6
6 8
9 10
*/
using namespace std;
vector<unordered_set<int>> getGroups(int n,int e,vector<unordered_set<int>> group,vector<int> par){
    for(int k=0;k<e;k++){
        int a,b;
        cin>>a>>b;
        // for(auto itr:par){
        // cout<<itr<<" ";
        // }
        // cout<<endl;
        if(par[a]!=par[b]){
            int minPar=min(par[a],par[b]);
            if(par[a]<par[b]){
                while(group[b].size()!=0){
                    auto num=group[b].begin();
                    group[b].erase(num);
                    group[minPar].insert(*num);
                }
            }
            else{
                while(group[a].size()!=0){
                    auto num=group[a].begin();
                    group[a].erase(num);
                    group[minPar].insert(*num);
                }
            }
            par[a]=minPar;
            par[b]=minPar;
        }
    }
    // for(auto itr:par){
    //     cout<<itr<<" ";
    // }
    // cout<<endl;
    return group;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> par(n+1);
    par.reserve(n+1);
    vector<unordered_set<int>> group(n+1);
    for(int i=0;i<=n;i++){
        par[i]=i;
        group[i].insert(i);
    }
    group=getGroups(n,e,group,par);
    group.erase(group.begin());
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        if(group[i].size()!=0){
            cout<<i+1<<":";
            for(auto itr:group[i]){
                cout<<itr<<" ";
            }
            cout<<endl;
        }
    }
}
