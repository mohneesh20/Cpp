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
void CompareNodes(Node* node,int sum,Node* root){
    if(root->left!=nullptr){
        CompareNodes(node,sum,root->left);
    }
    if(root->right!=nullptr){
        CompareNodes(node,sum,root->right);
    }
    cout<<node->data<<":"<<root->data<<endl;
    // if(node->data+root->data==sum){
    // }
}
void PairSum(Node* root,int sum,Node* parentRoot){
    if(root->left!=nullptr){
        PairSum(root->left,sum,root);
    }
    if(root->right!=nullptr){
        PairSum(root->right,sum,root);
    }
    cout<<root->data<<":";
    CompareNodes(root,sum,parentRoot);
}
int main(){
    Node *root=takeLevelInput();
    printTree(root);
    int sum;
    cout<<"ENTER THE DESIRED SUM:";
    cin>>sum;
    PairSum(root,sum,root);
}