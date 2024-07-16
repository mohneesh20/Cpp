#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left=nullptr;
    Node *right=nullptr;
    Node(int x):data(x){}
};
Node* takeInput(){
    int rootData;
    cout<<"ENTER THE ROOT DATA:";
    cin>>rootData;
    cout<<endl;
    if(rootData==-1){
        return nullptr;
    }
    Node *root=new Node(rootData);
    Node *leftData=takeInput();
    Node *rightData=takeInput();
    root->left=leftData;
    root->right=rightData;
    return root;
}
void printTree(Node *root){
    if(root==nullptr){
        return;
    }
    cout<<root->data;
    if(root->left!=nullptr){
    cout<<":L"<<root->left->data;
    }
    else{
    }
    if(root->right!=nullptr){
    cout<<":R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int main(){
    Node *root=takeInput();
    printTree(root);
}
