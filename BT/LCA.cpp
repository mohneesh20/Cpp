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
class Data{
    public:
    bool flag=false;
    Node* node=nullptr;
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
            cout<<"L-"<<root->left->data<<":";
            pendingNodes.push(root->left);
        }
        if(root->right!=nullptr){
            cout<<"R-"<<root->right->data<<":";
            pendingNodes.push(root->right);
        }
        cout<<endl;
    }
}
Data LCA(Node* root,int FirstNode,int SecondNode){
        Data flag1,flag2;
        if(root==nullptr){
            return flag1;
        }
        if(root->left!=nullptr){
            flag1=LCA(root->left,FirstNode,SecondNode);
        }
        if(root->right!=nullptr){
            flag2=LCA(root->right,FirstNode,SecondNode);
        }
        // cout<<root->data<<" "<<flag1.flag<<"-"<<flag1.node<<" "<<flag2.flag<<"-"<<flag2.node<<endl;
        if(flag1.flag&&flag2.flag){
            Data result;
            result.flag=false;
            // cout<<root->data<<endl;
            result.node=root;
            return result;
        }
        if(flag2.flag||flag1.flag){
            Data result;
            result.flag=true;
            if(root->data==FirstNode||root->data==SecondNode){
                result.flag=false;
                result.node=root;
                return result;
            }
            else{
                return result;
            }
        }
        if(root->data==FirstNode||root->data==SecondNode){
            Data result;
            result.flag=true;
            return result;
        }
        if(flag1.node!=nullptr){
            return flag1;
        }
        else{
            return flag2;
        }
        
}
int main(){
    Node* root=takeLevelInput();
    printTree(root);
    int FirstNode,SecondNode;
    cout<<"ENTER FIRST NODE:";
    cin>>FirstNode;
    cout<<"ENTER SECOND NODE:";
    cin>>SecondNode;
    cout<<endl;
    Data result=LCA(root,FirstNode,SecondNode);
    if(result.node){
        cout<<result.node->data;
    }
    else{
        cout<<"null";
    }
}