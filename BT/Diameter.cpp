#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left=nullptr;
    Node *right=nullptr;
    Node(int x):data(x){}
};
Node *takeLevelInput(){
    queue<Node*> pendingNodes;
    int rootData;
    cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    cout<<endl;
    if(rootData==-1){
        return nullptr;
    }
    Node *root=new Node(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        auto parnt=pendingNodes.front();
        pendingNodes.pop();
        int left,right;
        cout<<"LEFT:";
        cin>>left;
        cout<<endl;
        if(left!=-1){
        Node *leftNode=new Node(left);
        parnt->left=leftNode;
        pendingNodes.push(leftNode);
        }
        cout<<"RIGHT:";
        cin>>right;
        cout<<endl;
        if(right!=-1){
        Node *rightNode=new Node(right);
        parnt->right=rightNode;
        pendingNodes.push(rightNode);
        }
    }
    return root;
}
void printTree(Node *root){
    queue<Node*> pendingNodes;
    if(root==nullptr){
        return;
    }
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node *root=pendingNodes.front();
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
int Height(Node* root){
    if(root==nullptr){
        return 0;
    }
    return(1+max(Height(root->left),Height(root->right)));
}
pair<int,int> Diameter(Node* root){
    if(root==nullptr){
        pair<int,int> res;
        res.first=0;
        res.second=0;
        return(res);
    }
    pair<int,int> leftData=Diameter(root->left);
    pair<int,int> rightData=Diameter(root->right);
    int height=1+max(leftData.first,rightData.first);
    int diameter=max(leftData.first+rightData.first,max(leftData.second,rightData.second));
    pair<int,int> result;
    result.first=height;
    result.second=diameter;
    return(result);
}
int main(){
    Node* root=takeLevelInput();
    // cout<<Height(root);
    printTree(root);
    // pair<int,int> dia=Diameter(root);
    // cout<<"Diameter:"<<dia.second<<endl;
    // cout<<"Height:"<<dia.first<<endl;
}