#include<bits/stdc++.h>
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
    if(rootData==-1){
        return nullptr;
    }
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
vector<int> Diagonal(Node *root){
    queue<pair<Node*,int>> q;
    vector<int> result;
    q.push(make_pair(root,0));
    unordered_map<int,vector<int>> mp;
    int idx=-1;
    while(q.size()!=0){
        pair<Node*,int> p=q.front();
        q.pop();
        idx=max(idx,p.second);
        mp[p.second].emplace_back(p.first->data);
        if(p.first->left!=nullptr){
            q.push(make_pair(p.first->left,p.second+1));
        }
        if(p.first->right!=nullptr){
            q.push(make_pair(p.first->right,p.second));
        }
    }
    for(int i=0;i<=idx;i++){
        for(auto &itr:mp[i]){
            result.push_back(itr);
        }
    }
    return result;
}
int main(){
    // Node* root=takeLevelInput();
    Node* root=new Node(1);
    Node *lft,*rgt;
    lft=new Node(2);
    rgt=new Node(3);
    root->left=lft;
    root->right=rgt;
    vector<int> res=Diagonal(root);
    for(auto &num:res){
    cout<<num<<" ";
    }
}