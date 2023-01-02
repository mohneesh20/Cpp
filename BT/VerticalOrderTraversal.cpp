#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    TreeNode* data;
    int indx;
    int ht;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<Solution> q;
        Solution node;
        node.data=root;
        node.indx=0;
        node.ht=0;
        mp[0].push_back(root->val);
        q.push(node);
        while(q.size()!=0){
            Solution nde=q.front();
            q.pop();
            if(nde.data->left!=nullptr){
                Solution tmpNode;
                tmpNode.data=nde.data->left;
                tmpNode.indx=nde.indx-1;
                tmpNode.ht=nde.ht+1;
                // cout<<tmpNode.data->val<<" "<<mp[tmpNode.indx].size()<<endl;
                // mp[tmpNode.indx].push_back(tmpNode.data->val);
                if(mp[tmpNode.indx].size()!=0){
                    if(mp[tmpNode.indx][tmpNode.ht]>tmpNode.data->val){
                        int tmp=mp[tmpNode.indx][tmpNode.ht];
                        mp[tmpNode.indx][tmpNode.ht]=tmpNode.data->val;
                        tmpNode.data->val=tmp;
                        mp[tmpNode.indx].push_back(tmpNode.data->val);
                    }
                    else{
                        mp[tmpNode.indx].push_back(tmpNode.data->val);
                    }
                }
                q.push(tmpNode);
            }
            if(nde.data->right!=nullptr){
                Solution tmpNode;
                tmpNode.data=nde.data->right;
                tmpNode.indx=nde.indx+1;
                tmpNode.ht=nde.ht+1;
                // cout<<tmpNode.data->val<<" "<<mp[tmpNode.indx].size()<<endl;
                if(mp[tmpNode.indx].size()!=0){
                    if(mp[tmpNode.indx][tmpNode.ht]>tmpNode.data->val){
                        int tmp=mp[tmpNode.indx][tmpNode.ht];
                        mp[tmpNode.indx][tmpNode.ht]=tmpNode.data->val;
                        tmpNode.data->val=tmp;
                        mp[tmpNode.indx].push_back(tmpNode.data->val);
                    }
                    else{
                        mp[tmpNode.indx].push_back(tmpNode.data->val);
                    }
                }
                q.push(tmpNode);
            }
        }
        vector<vector<int>> result;
        for(auto itr:mp){
            cout<<itr.first<<":";
            // result.push_back(itr.second);
            for(auto itr2:itr.second){
                cout<<itr2<<" ";
            }
            cout<<endl;
        }
        return result;
    }
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
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    Solution res;
    TreeNode* root=takeLevelInput();
    res.verticalTraversal(root);
}