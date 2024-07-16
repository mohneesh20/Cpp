#include<bits/stdc++.h>
using namespace std;
//1 10 4 3 -1 7 9 12 8 6 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
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
bool isEvenOddTree(TreeNode* root){
    if(root->val%2==0) return false;
    queue<TreeNode*> q;
    q.push(root);
    bool flag=false;
    while(q.size()!=0){
        int n=q.size();
        if(!flag){
            int mx=INT32_MAX;
            for(int i=0;i<n;i++){
                TreeNode* nde=q.front();
                q.pop();
                TreeNode* lft=nde->left;
                TreeNode* rgt=nde->right;
                if(lft!=nullptr){
                    if(lft->val<mx&&lft->val%2==0){
                        mx=lft->val;
                        q.push(lft);
                    }else return false;
                }
                if(rgt!=nullptr){
                    if(rgt->val<mx&&rgt->val%2==0){
                        mx=rgt->val;
                        q.push(rgt);
                    }else return false;
                }
            }
            flag=true;
        }else{
            int mn=INT32_MIN;
            for(int i=0;i<n;i++){
                TreeNode* nde=q.front();
                q.pop();
                TreeNode* lft=nde->left;
                TreeNode* rgt=nde->right;
                if(lft!=nullptr){
                    if(lft->val>mn&&lft->val%2!=0){
                        mn=lft->val;
                        q.push(lft);
                    }else return false;
                }
          
                if(rgt!=nullptr){
                    if(rgt->val>mn&&rgt->val%2!=0){
                        mn=rgt->val;
                        q.push(rgt);
                    }else return false;
                }
            }
            flag=false;
        }
    }
    return true;
}
int main(){
    TreeNode *root=takeLevelInput();
    printTree(root);
    cout<<endl<<isEvenOddTree(root)<<endl;  
}