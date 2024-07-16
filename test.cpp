#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left=nullptr;
    TreeNode *right=nullptr;
    TreeNode(int x):val(x){}
};
TreeNode *takeLevelInput(){
    queue<TreeNode*> pendingTreeNodes;
    int rootval;
    // cout<<"ENTER ROOT val:";
    cin>>rootval;
    // cout<<endl;
    TreeNode *root=new TreeNode(rootval);
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
string getDirections(TreeNode* root, int startValue, int destValue) {
        
}
//1 2 3 -1 -1 -1 -1
int main(){
    TreeNode* root=takeLevelInput();
    
}