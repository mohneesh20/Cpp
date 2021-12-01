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
// class MinMax{
//     public:
//     int Max;
//     int Min;
// };
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
void printNodeAtDistance(Node* root,int counter,int depth,int depthNode,bool flag){
    if(root->data==depthNode){
        cout<<"ROOT:"<<root->data<<endl;
        flag=true;
    }
    if(counter==depth && flag){
        cout<<"NODE:"<<root->data<<endl;
        return;
    }
    if(root->left!=nullptr){
        if(flag){
            printNodeAtDistance(root->left,++counter,depth,depthNode,flag);
        }
        else{
            printNodeAtDistance(root->left,0,depth,depthNode,flag);
        }
    }
    counter--;
    if(root->right!=nullptr){
        if(flag){
            printNodeAtDistance(root->right,++counter,depth,depthNode,flag);
        }
        else{
            printNodeAtDistance(root->right,0,depth,depthNode,flag);
        }
    }
}
int main(){
    Node* root=takeLevelInput();
    printTree(root);
    cout<<"ENTER NODE:";
    int node;
    cin>>node;
    cout<<"DISTANCE:";
    int dis;
    cin>>dis;
    bool flag=false;
    printNodeAtDistance(root,0,dis,node,flag);
}