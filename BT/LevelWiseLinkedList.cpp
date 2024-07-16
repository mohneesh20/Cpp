#include<iostream>
#include<queue>
#include<stack>
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
    int val;
    Node *next=nullptr;
    Node(int x):val(x){}
};
TreeNode *takeLevelInput(){
    queue<TreeNode*> pendingTreeNodes;
    int rootData;
    cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    cout<<endl;
    TreeNode *root=new TreeNode(rootData);
    pendingTreeNodes.push(root);
    while(pendingTreeNodes.size()!=0){
        auto parnt=pendingTreeNodes.front();
        pendingTreeNodes.pop();
        int left,right;
        cout<<"LEFT:";
        cin>>left;
        cout<<endl;
        if(left!=-1){
        TreeNode *leftTreeNode=new TreeNode(left);
        parnt->left=leftTreeNode;
        pendingTreeNodes.push(leftTreeNode);
        }
        cout<<"RIGHT:";
        cin>>right;
        cout<<endl;
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
        cout<<root->data<<":";
        if(root->left!=nullptr){
            cout<<"L"<<root->left->data<<":";
            pendingTreeNodes.push(root->left);
        }
        if(root->right!=nullptr){
            cout<<"R"<<root->right->data<<":";
            pendingTreeNodes.push(root->right);
        }
        cout<<endl;
    }
}
int HeightTree(TreeNode *root){
    int ht=0,tmp;
    if(root==nullptr){
        return ht;
    }
    if(root->left!=nullptr){
        tmp=HeightTree(root->left);
        if(tmp>ht){
            ht=tmp;
        }
    }
    if(root->right!=nullptr){
        tmp=HeightTree(root->right);
        if(tmp>ht){
            ht=tmp;
        }
    }
    return (ht+1);
}
vector<Node*> LevelWiseLinkedList(TreeNode *root){
    queue<TreeNode*> Layer1;
    queue<TreeNode*> Layer2;
    bool flag=true;
    Node* tmp;
    int height=HeightTree(root);
   
    vector<Node*> LvlList;
    LvlList.reserve(height);
    Layer1.push(root);
    while(Layer1.size()!=0 || Layer2.size()!=0){
        while(Layer1.size()!=0){
            TreeNode *node1=Layer1.front();
            if(node1!=nullptr){
            Layer2.push(node1->left);
            Layer2.push(node1->right);
                if(flag){
                    tmp=new Node(node1->data);
                    LvlList.push_back(tmp);
                    flag=false;   
                }
                else{
                    Node* tailNodes=new Node(node1->data);
                    tmp->next=tailNodes;
                    tmp=tmp->next;
                }
            }
            Layer1.pop();
        }
        cout<<endl;
        flag=true;
        while(Layer2.size()!=0){
            TreeNode *node1=Layer2.front();
            if(node1!=nullptr){
            Layer1.push(node1->left);
            Layer1.push(node1->right);
                if(flag){
                    tmp=new Node(node1->data);
                    LvlList.push_back(tmp);
                    flag=false;   
                }
                else{
                    Node* tailNodes=new Node(node1->data);
                    tmp->next=tailNodes;
                    tmp=tmp->next;
                }
            }
            Layer2.pop();
        }
        cout<<endl;
        flag=true;
    }
    return(LvlList);
}
int main(){
    TreeNode* root=takeLevelInput();
    printTree(root);
    cout<<endl;
    auto result=LevelWiseLinkedList(root);
    for(auto node:result){
        while(node!=nullptr){
            cout<<node->val<<"->";
            node=node->next;
        }
        cout<<endl;
    }
}