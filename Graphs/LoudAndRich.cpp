#include<iostream>
#include<vector>
using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
void getAns(int node,vector<vector<int>> graph,vector<int> quiet,vector<int> &answer,int start){
    cout<<start<<"-"<<quiet[start]<<":"<<node<<"-"<<quiet[node]<<endl;
    if(quiet[start]>quiet[node]){
        answer[start]=node;
        // quiet[start]=quiet[node];
    }
    cout<<endl;
    for(int i=0;i<graph[node].size();i++){
        getAns(graph[node][i],graph,quiet,answer,start);
    }
}
int main(){
    vector<vector<int>> richer = {{0,1},{1,2}};
    vector<int> quiet = {1,0,2};
    vector<vector<int>> graph(quiet.size());
    for(auto i:richer){
        graph[i[1]].push_back(i[0]);
    }
    int counter=0;
    vector<int> answer(quiet.size());
    for(int i=0;i<quiet.size();i++){
        answer[i]=i;
    }
    for(int i=0;i<quiet.size();i++){
    // for(int i=0;i<1;i++){
        getAns(i,graph,quiet,answer,i);
        cout<<endl;
        cout<<endl;
    }
    // for(auto i:graph){
    //     cout<<counter<<":";
        for(auto j:answer){
           cout<<j<<' '; 
        }
    //     counter++;
    //     cout<<endl;
    // }
}