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
/*
50
[[41,40],[9,32],[48,14],[6,44],[18,41],[41,1],[7,41],[38,41],[19,4],[16,41],[41,43],[41,22],[41,21],[9,0],[41,48],[32,36],[24,44],[39,41],[48,17],[49,15],[47,41],[19,31],[11,41],[41,23],[41,49],[45,44],[2,49],[13,41],[35,41],[30,0],[5,44],[8,0],[41,20],[41,28],[12,11],[12,41],[49,10],[19,0],[0,37],[34,41],[42,48],[27,41],[0,41],[19,44],[41,26],[41,29],[33,41],[49,46],[41,25],[3,41]]
40
3*/
using namespace std;
vector<unordered_set<int>> getGroups(int n,int e,vector<unordered_set<int>> group,vector<int> par){
    for(int k=0;k<e;k++){
        int a,b;
        cin>>a>>b;
        if(par[a]!=par[b]){
            int minPar=min(par[a],par[b]);
            if(par[a]<par[b]){
                while(group[b].size()!=0){
                    auto num=group[b].begin();
                    group[minPar].insert(*num);
                    par[*num]=minPar;
                    group[b].erase(num);
                }
            }
            else{
                while(group[a].size()!=0){
                    auto num=group[a].begin();
                    group[minPar].insert(*num);
                    par[*num]=minPar;
                    group[a].erase(num);
                }
            }
            par[a]=minPar;
            par[b]=minPar;
        }
    }
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
    cout<<endl;
    for(int i=0;i<=n;i++){
        if(group[i].size()!=0){
            cout<<i<<":";
            for(auto itr:group[i]){
                cout<<itr<<" ";
            }
            cout<<endl;
        }
    }
}
