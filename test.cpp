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
    queue<TreeNode*> pendingNodes;
    int rootData;
    // cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    // cout<<endl;
    TreeNode *root=new TreeNode(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        auto parnt=pendingNodes.front();
        pendingNodes.pop();
        int left,right;
        // cout<<"LEFT:";
        cin>>left;
        // cout<<endl;
        if(left!=-1){
        TreeNode *leftNode=new TreeNode(left);
        parnt->left=leftNode;
        pendingNodes.push(leftNode);
        }
        // cout<<"RIGHT:";
        cin>>right;
        // cout<<endl;
        if(right!=-1){
        TreeNode *rightNode=new TreeNode(right);
        parnt->right=rightNode;
        pendingNodes.push(rightNode);
        }
    }
    return root;
}
// struct Node{
//     int val;
//     Node* parent;
//     Node* left;
//     Node* right;
//     Node(int x):val(x),parent(nullptr),left(nullptr),right(nullptr){}
// };
// Node* dfs(TreeNode* root,int s,Node** head,Node* parent){
//     if(root==nullptr) return nullptr;
//     Node* new_root=new Node(root->val);
//     new_root->parent=parent;
//     new_root->left=dfs(root->left,s,head,new_root);
//     new_root->right=dfs(root->right,s,head,new_root);
//     if(new_root->val==s) *head=new_root;
//     return new_root;
// }
//2 1 -1 -1 -1
//5 1 2 3 -1 6 4 -1 -1 -1 -1 -1 -1
int main(){
   TreeNode *root=takeLevelInput();
//    Node* head;
   int startValue=3;
   int destValue=6;
//    dfs(root,startValue,&head,nullptr);
//    queue<pair<Node*,string>> q;
//    unordered_map<int,bool> visited;
//    q.push(make_pair(head,""));
//    visited[head->val]=true;
//    while(q.size()!=0){
//     pair<Node*,string> node=q.front();
//     q.pop();
//     if(destValue==node.first->val){
//         cout<<node.second<<endl;
//         break;
//     }
//     if(node.first->parent!=nullptr&&visited[node.first->parent->val]==false){
//         q.push(make_pair(node.first->parent,node.second+"U"));
//         visited[node.first->parent->val]=true;
//     }
//     if(node.first->left!=nullptr&&visited[node.first->left->val]==false){
//         q.push(make_pair(node.first->left,node.second+"L"));
//         visited[node.first->left->val]=true;
//     }
//     if(node.first->right!=nullptr&&visited[node.first->right->val]==false){
//         q.push(make_pair(node.first->right,node.second+"R"));
//         visited[node.first->right->val]=true;
//     }
//    }
}