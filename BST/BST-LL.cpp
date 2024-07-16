#include<iostream>
#include<queue>
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
    Node* next=nullptr;
    Node(int x):data(x),next(nullptr){}
    Node(int x,Node* next):data(x),next(next){}
};
class ResData{
    public:
    Node* head=nullptr;
    Node* tail=nullptr;
};
class isBstRes{
public:
    int minimum;
    int maximum;
    bool isBST;
};
TreeNode *takeLevelInput(){
    queue<TreeNode*> pendingTreeNodes;
    int rootData;
    // cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    // cout<<endl;
    if(rootData==-1){
        return nullptr;
    }
    TreeNode *root=new TreeNode(rootData);
    pendingTreeNodes.push(root);
    while(pendingTreeNodes.size()!=0){
        auto parnt=pendingTreeNodes.front();
        pendingTreeNodes.pop();
        int left,right;
        // cout<<"LEFT:";
        cin>>left;
        // cout<<endl;
        if(left!=-1){
        TreeNode *leftTreeNode=new TreeNode(left);
        parnt->left=leftTreeNode;
        pendingTreeNodes.push(leftTreeNode);
        }
        // cout<<"RIGHT:";
        cin>>right;
        // cout<<endl;
        if(right!=-1){
        TreeNode *rightTreeNode=new TreeNode(right);
        parnt->right=rightTreeNode;
        pendingTreeNodes.push(rightTreeNode);
        }
    }
    return root;
}
void printTree(TreeNode *root){
    queue<TreeNode*> pendingTreeNodes;
    if(root==nullptr){
        return;
    }
    pendingTreeNodes.push(root);
    while(pendingTreeNodes.size()!=0){
        TreeNode *root=pendingTreeNodes.front();
        pendingTreeNodes.pop();
        // cout<<root->data<<":";
        if(root->left!=nullptr){
            // cout<<"L"<<root->left->data<<":";
            pendingTreeNodes.push(root->left);
        }
        if(root->right!=nullptr){
            // cout<<"R"<<root->right->data<<":";
            pendingTreeNodes.push(root->right);
        }
        cout<<endl;
    }
}
isBstRes isBinarySearchTree(TreeNode* root){
    if(root==nullptr){
        isBstRes output;
        output.minimum=INT32_MAX;
        output.maximum=INT32_MIN;
        output.isBST=true;
        return output;
    }
    isBstRes leftData=isBinarySearchTree(root->left);
    isBstRes rightData=isBinarySearchTree(root->right);
    int minimum=min(root->data,min(leftData.minimum,rightData.minimum));
    int maximum=max(root->data,max(leftData.maximum,rightData.maximum));
    bool isBST=(root->data>leftData.maximum)&&(root->data<rightData.minimum)&&(leftData.isBST)&&(rightData.isBST);
    isBstRes output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBST;
    return output;
}
ResData SortedLinkedList(TreeNode* root){
    if(root==nullptr){
        ResData output;
        output.head=nullptr;
        output.tail=nullptr;
        return output;
    }
    ResData leftData=SortedLinkedList(root->left);
    if(leftData.head==nullptr){
        leftData.head=new Node(root->data);
        leftData.tail=leftData.head;
    }
    else{
        Node* tmp=new Node(root->data);
        leftData.tail->next=tmp;
        leftData.tail=tmp;
    }
    ResData rightData=SortedLinkedList(root->right);
    if(rightData.head!=nullptr){
        leftData.tail->next=rightData.head;
        leftData.tail=rightData.tail;
    }
    ResData output;
    output.head=leftData.head;
    output.tail=leftData.tail;
    return output;
}
int main(){
    TreeNode* root=takeLevelInput();
    isBstRes result=isBinarySearchTree(root);
    // cout<<result.isBST<<endl;
    if(result.isBST){
        ResData result=SortedLinkedList(root);
        if(!result.head){
            cout<<"LinkedList is nullptr";
        }
        else{
            while(result.head!=nullptr){
                cout<<result.head->data<<"->";
                result.head=result.head->next;
            }
        }
        // cout<<result.head->data;
        // while(result.head!=nullptr){
        //     cout<<result.head->data<<"->";
        //     result.head=result.head->next;
        // }
    }
    else{
        cout<<"TREE NOT BALANCED";
    }
}