#include<bits/stdc++.h>
using namespace std;
//1 4 3 2 4 2 5 -1 -1 -1 -1 -1 -1 4 6 -1 -1 -1 -1
//4 3 -1 1 2 -1 -1 -1 -1
//-4 -2 -5 -1 -1 -1 -1
class TreeNode{
    public:
    int data;
    TreeNode *left=nullptr;
    TreeNode *right=nullptr;
    TreeNode(int x):data(x){}
};
class container{
    public:
    bool flag;
    int mn;
    int mx;
    int sum;
    container():flag(true),mn(INT32_MAX),mx(INT32_MIN),sum(0){}
};
int mx_sum=0;
container* MaxSumArr(TreeNode* root){
    if(root==nullptr){
        container* temp = new container();
        return temp;
    }
    container* lft=MaxSumArr(root->left);
    container* rgt=MaxSumArr(root->right);
    if((!lft->flag)||(!rgt->flag)){
        container* temp = new container();
        temp->flag=false;
        temp->mn=-1;
        temp->mx=-1;
        temp->sum=max(lft->sum,rgt->sum);
        mx_sum=max(mx_sum,temp->sum);
        return temp;
    }else{
        if((lft->mx<root->data)&&(rgt->mn>root->data)){
           container* temp = new container();
           temp->flag=true;
           if(lft->mn==INT32_MAX){
            temp->mn=root->data;
           }else{
            temp->mn=lft->mn;
           }
           if(rgt->mx==INT32_MIN){
            temp->mx=root->data;
           }else{
            temp->mx=rgt->mx;
           }
           temp->sum=root->data+lft->sum+rgt->sum;
           mx_sum=max(mx_sum,temp->sum);
           return temp;
        }else{
            container* temp = new container();
            temp->flag=false;
            temp->mn=-1;
            temp->mx=-1;
            temp->sum=max(lft->sum,rgt->sum);
            mx_sum=max(mx_sum,temp->sum);
            return temp;
        }
    }
}
void printTree(TreeNode *root){
    queue<TreeNode*> pendingNodes;
    if(root==nullptr){
        return;
    }
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode *root=pendingNodes.front();
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
TreeNode *takeLevelInput(){
    queue<TreeNode*> pendingNodes;
    int rootData;
    cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    cout<<endl;
    TreeNode *root=new TreeNode(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        auto parnt=pendingNodes.front();
        pendingNodes.pop();
        int left,right;
        cout<<"LEFT:";
        cin>>left;
        cout<<endl;
        if(left!=-1){
        TreeNode *leftNode=new TreeNode(left);
        parnt->left=leftNode;
        pendingNodes.push(leftNode);
        }
        cout<<"RIGHT:";
        cin>>right;
        cout<<endl;
        if(right!=-1){
        TreeNode *rightNode=new TreeNode(right);
        parnt->right=rightNode;
        pendingNodes.push(rightNode);
        }
    }
    return root;
}
int main(){
    TreeNode *root=takeLevelInput();
    // printTree(root);
    container* result=MaxSumArr(root);
    cout<<mx_sum<<endl;
}
