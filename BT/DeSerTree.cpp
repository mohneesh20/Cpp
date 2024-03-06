#include<bits/stdc++.h>
using namespace std;
//1 2 3 -1 -1 4 5 -1 -1 -1 -1
class TreeNode{
    public:
    int val;
    TreeNode *left=nullptr;
    TreeNode *right=nullptr;
    TreeNode(int x):val(x){}
};
void printTree(TreeNode *root){
    queue<TreeNode*> pendingNodes;
    if(root==nullptr){
        return;
    }
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode *root=pendingNodes.front();
        pendingNodes.pop();
        cout<<root->val<<":";
        if(root->left!=nullptr){
            cout<<"L"<<root->left->val<<":";
            pendingNodes.push(root->left);
        }
        if(root->right!=nullptr){
            cout<<"R"<<root->right->val<<":";
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
string dfs(TreeNode* root){
    if(root==nullptr){
        return "";
    }
    string l=dfs(root->left);
    string r=dfs(root->right);
    return l+"|"+to_string(root->val)+"|"+r;
}
string serialize(TreeNode* root) {
    // string s="#"+to_string(root->val)/+"#";
    cout<<dfs(root->left);
    cout<<endl<<dfs(root->right);
}
int main(){
    TreeNode *root=takeLevelInput();
    // printTree(root);
    serialize(root);
   
}