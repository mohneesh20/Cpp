#include <iostream>
#include<vector>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
    // Edge(int s,int d,int w):source(s),dest(d),weight(w){}
};
void bellmanFord(vector<Edge> edges,int n,int src){
    int* dist=new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INT32_MAX;
    }
    dist[src]=0;
    for(int i=1;i<n-1;i++){
        for(int j=0;j<edges.size();j++){
            int u=edges[j].source;
            int v=edges[j].dest;
            int w=edges[j].weight;
            if(dist[u]!=INT32_MAX&&dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int i=0;i<edges.size();i++){
            int u=edges[i].source;
            int v=edges[i].dest;
            int w=edges[i].weight;
            if(dist[u]!=INT32_MAX&&dist[u]+w<dist[v]){
                cout<<"Graph contains a negative weight";
                return;
            }       
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<Edge> edges;
    edges.reserve(e);
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        Edge tmp;
        tmp.source=s;
        tmp.dest=d;
        tmp.weight=w;
        edges.push_back(tmp);
    }
    bellmanFord(edges,n,0);
    // vector<int> dist=bellmanFord(edges,n,start);
}
