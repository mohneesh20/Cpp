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
int MinInBT(Node* root){
    int min=root->data;
    if(root->left!=nullptr){
        int tmp=MinInBT(root->left);
        if(tmp<min){
            min=tmp;
        }
    }
    if(root->right!=nullptr){
        int tmp=MinInBT(root->right);
        if(tmp<min){
            min=tmp;
        }
    }
    return min;
}
int MaxInBT(Node* root){
    int max=root->data;
    if(root->left!=nullptr){
        int tmp=MaxInBT(root->left);
        if(tmp>max){
            max=tmp;
        }
    }
    if(root->right!=nullptr){
        int tmp=MaxInBT(root->right);
        if(tmp>max){
            max=tmp;
        }
    }
    return max;
}
int main(){
    Node* root=takeLevelInput();
    printTree(root);
    int max=MaxInBT(root);
    int min=MinInBT(root);
    cout<<"MAX:"<<max<<" "<<"MIN:"<<min;
}