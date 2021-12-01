#include<iostream>
#include<queue>
#include<stack>
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
void ZigZag(Node* root){
    stack<Node*> Layer1;
    stack<Node*> Layer2;
    Layer1.push(root);
    while(Layer1.size()!=0 || Layer2.size()!=0){
        // cout<<"Layer1:"<<Layer1.size()<<endl;
        while(Layer1.size()!=0){
            Node *node1=Layer1.top();
            if(node1!=nullptr){
            Layer2.push(node1->left);
            Layer2.push(node1->right);
            cout<<node1->data<<" ";
            }
            Layer1.pop();
        }
        // cout<<"Layer2:"<<Layer2.size()<<endl;
        while(Layer2.size()!=0){
            Node *node1=Layer2.top();
            if(node1!=nullptr){
            Layer1.push(node1->right);
            Layer1.push(node1->left);
            cout<<node1->data<<" ";
            }
            Layer2.pop();
        }
    }
}
int main(){
    Node* root=takeLevelInput();
    printTree(root);
    cout<<endl;
    ZigZag(root);
}