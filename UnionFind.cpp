#include<iostream>
#include<vector>
using namespace std;
class UnionFind{
    public:
    // int size;//Number of elements in Union Find
    vector<int> sz;//Sizes of each component
    vector<int> id;//parent array for union find
    int NumOfComponents;//Total number of connected components
    UnionFind(int NumberOfNodes){
        // if(size<=0){
        //     return;
        // }
        // size=NumberOfNodes;
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
    bool connected(int node1,int node2){
        return (find(node1)==find(node2));
    }
    int componentSize(int node){
        return sz[(find(node))];
    }
    // int size(){
    //     return size;
    // }
    int numofComp(){
        return NumOfComponents;
    }
    void unify(int node1,int node2){
        int root1=find(node1);
        int root2=find(node2);

        if(root1==root2) return;

        if(sz[root1]<sz[root2]){
            sz[root2]+=sz[root1];
            id[root1]=root2;
        }
        else{
            sz[root1]+=sz[root2];
            id[root2]=root1;
        }
        NumOfComponents--;
    }
};
int main(){
    vector<vector<int>> edges={{5,0},{1,0},{10,7},{9,8},{7,2},{1,3},{0,2},{8,5},{4,6},{4,2}};
    int n=11;
    UnionFind uf(n);
    for(int i=0;i<edges.size();i++){
        uf.unify(edges[i][0],edges[i][1]);
    }
    cout<<uf.NumOfComponents;
    cout<<endl;
    for(auto &itr:uf.sz){
        cout<<itr<<" ";
    }
    // for(auto &itr:uf.id){
    //     cout<<itr<<" ";
    // }
}