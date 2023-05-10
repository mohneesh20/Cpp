#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class UnionFind{
    int size;//Number of elements in Union Find
    vector<int> sz;//Sizes of each component
    vector<int> id;//parent array for union find
    int NumOfComponents;//Total number of connected components
    public:
    UnionFind(int NumberOfNodes){
        if(size<=0){
            return;
        }
        size=NumberOfNodes;
        NumOfComponents=NumberOfNodes;
        sz.resize(NumberOfNodes);
        id.resize(NumberOfNodes);
        for(int i=0;i<NumberOfNodes;i++){
            id[i]=i;
            sz[i]=1;
        }
    }
    int find(int node){
        int root=node;
        while(root!=id[root]){
            root=id[root];
        }
        while(node!=root){
            int next=id[node];
            id[node]=root;
            node=next;
        }
        return root;
    }
};