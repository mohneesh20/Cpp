#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left=nullptr;
    TreeNode *right=nullptr;
    TreeNode(int x):data(x){}
};
class Node{
    public:
    int data;
    Node* prev=nullptr;
    Node* next=nullptr;
    Node(int x):data(x){} 
};
pair<Node*,Node*> bToDLL(TreeNode *root){
    if(root->left==nullptr&&root->right){
        Node *curNode=new Node(root->data);
        return make_pair(curNode,curNode);
    };
    pair<Node*,Node*> lft=bToDLL(root->left);
    pair<Node*,Node*> rgt=bToDLL(root->right);
    Node *curNode=new Node(root->data);
    lft.second->next=curNode;
    curNode->prev=lft.second;
    rgt.first->prev=curNode;
    curNode->next=rgt.first;
    return make_pair(lft.first,rgt.second);
}
int main(){
    TreeNode* root;
    bToDLL(root);
}