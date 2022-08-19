#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left=nullptr;
    Node *right=nullptr;
    Node(int x):data(x){}
};
Node *takeLevelInput(){
    queue<Node*> pendingNodes;
    int rootData;
    cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    cout<<endl;
    Node *root=new Node(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        auto parnt=pendingNodes.front();
        pendingNodes.pop();
        int left,right;
        cout<<"LEFT:";
        cin>>left;
        cout<<endl;
        if(left!=-1){
        Node *leftNode=new Node(left);
        parnt->left=leftNode;
        pendingNodes.push(leftNode);
        }
        cout<<"RIGHT:";
        cin>>right;
        cout<<endl;
        if(right!=-1){
        Node *rightNode=new Node(right);
        parnt->right=rightNode;
        pendingNodes.push(rightNode);
        }
    }
    return root;
}
class Solution {
  public:
    map<int,pair<int,int>> m;
    void helper(Node*root,int hd,int l){
        if(root == NULL) return;
        if(m.find(hd) == m.end() || m[hd].second <= l){
            m[hd] = {root->data,l};
        }
        helper(root->left,hd-1,l+1);
        helper(root->right,hd+1,l+1);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        helper(root,0,0);
        vector<int> res;
        for(auto i:m){
            res.push_back(i.second.first);
        }
        return res;
    }
};
int main(){
    Node* root=takeLevelInput();
}