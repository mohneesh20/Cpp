#include<iostream>
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
void printTree(Node *root){
    queue<Node*> pendingNodes;
    if(root==nullptr){
        return;
    }
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node *root=pendingNodes.front();
        pendingNodes.pop();
        cout<<root->data<<":";
        if(root->left!=nullptr){
            cout<<"L"<<root->left->data<<":";
            pendingNodes.push(root->left);
        }
        if(root->right!=nullptr){
            cout<<"R"<<root->right->data<<":";
            pendingNodes.push(root->right);
        }
        cout<<endl;
    }
}
vector<int> result;
void LeftView(Node* root,int ht,int &mx){
    if(root==nullptr) return;
    if(ht>mx){
        mx=ht;
        result.emplace_back(root->data);
    }
    LeftView(root->left,ht+1,mx);
    LeftView(root->right,ht+1,mx);
}
int main(){
    Node *root=takeLevelInput();
    // printTree(root);
    int mx=0;
    LeftView(root,1,mx);
    for(auto itr:result){
        cout<<itr<<" ";
    }
}