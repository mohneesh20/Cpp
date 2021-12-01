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
void WithoutSibling(Node* root){
     if(root==nullptr){
         return;
     }
     if(root->left==nullptr){
         if(root->right!=nullptr){
             cout<<root->right->data<<" ";
             WithoutSibling(root->right);
         }
         else{
             return;
         }
     }
     else{
        if(root->right!=nullptr){
            WithoutSibling(root->right);
        }
     }
    if(root->right==nullptr){
         if(root->left!=nullptr){
             cout<<root->left->data<<" ";
             WithoutSibling(root->left);
         }
         else{
             return;
         }
     }
     else{
         if(root->left!=nullptr){
             WithoutSibling(root->left);
         }
     }
}
int main(){
    Node *root=takeLevelInput();
    printTree(root);
    cout<<endl;
    WithoutSibling(root);
}