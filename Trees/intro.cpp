#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int  data;
    vector<TreeNode*> children;
    TreeNode(int x):data(x){}
};
TreeNode* levelWisenput(){
    cout<<"ENTER ROOT DATA:";
    int rootData;
    cin>>rootData;
    cout<<endl;
    TreeNode*root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        auto front=pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"ENTER THE NUMBER OF CHILDREN:";
        cin>>n;
        cout<<endl;
        for(int i=0;i<n;i++){
            int childData;
            cin>>childData;
            TreeNode* child=new TreeNode(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;    
}
TreeNode* takeInput(){
    cout<<"ENTER ROOT DATA:";
    int rootData;
    cin>>rootData;
    cout<<endl;
    TreeNode* root=new TreeNode(rootData);
    int n;
    cout<<"ENTER THE NUMBER OF CHILDREN:";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        auto child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<"-";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){
    TreeNode* node1,*node2,*root;
    // root=takeInput();
    root=levelWisenput();
    // root=new TreeNode(1);
    // node1=new TreeNode(2);
    // node2=new TreeNode(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    printTree(root);
}