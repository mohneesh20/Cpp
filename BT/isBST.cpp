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
class isBstRes{
public:
    int minimum;
    int maximum;
    bool isBST;
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
isBstRes isBST(Node* root){
    if(root==nullptr){
        isBstRes output;
        output.minimum=INT32_MAX;
        output.maximum=INT32_MIN;
        output.isBST=true;
        return output;
    }
    auto leftData=isBST(root->left);
    auto righData=isBST(root->right);
    int minimum=min(root->data,min(leftData.minimum,righData.minimum));
    int maximum=max(root->data,max(leftData.maximum,righData.maximum));
    bool isBST=(root->data>leftData.maximum)&&(root->data<righData.minimum)&&(leftData.isBST&&righData.isBST);
    isBstRes output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBST;
    return output;
}
int main(){
    Node* root=takeLevelInput();
    printTree(root);
    auto result=isBST(root);
    cout<<endl<<result.isBST;
}