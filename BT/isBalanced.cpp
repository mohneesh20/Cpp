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
    int height=0,tmp;
    if(root->left!=nullptr){
        tmp=Height(root->left);
        if(tmp>height){
            height=tmp;
        }
    }
    if(root->right!=nullptr){
        tmp=Height(root->right);
        if(tmp>height){
            height=tmp;
        }
    }
    return(height+1);
}
bool isBalanced(Node* root){
    bool res=true;
    int ht1=-1,ht2=-1;
    if(root->left!=nullptr){
        bool res=isBalanced(root->left);
        if(!res){
            return res;
        }
        ht1=Height(root->left);
        // cout<<"LeftHeight:"<<ht1<<" ";
    }
    if(root->right!=nullptr){
        bool res=isBalanced(root->right);
        if(!res){
            return res;
        }
        ht2=Height(root->right);
        // cout<<"RightHeight:"<<ht2<<endl;
    }
    if(abs(ht1-ht2)<=1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    Node *root=takeLevelInput();
    printTree(root);
    bool result=isBalanced(root);
    if(result){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
} 