#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node* right=nullptr;
    Node* left=nullptr;
    Node(int x):data(x),right(nullptr),left(nullptr){}
};
Node* input(){
    queue<Node*> pendingNodes;
    int rootData;
    cout<<"ENTER ROOT DATA:";
    cin>>rootData;
    if(rootData==-1){
        return nullptr;
    }
    Node* root=new Node(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node* parent=pendingNodes.front();
        pendingNodes.pop();
        int nodeData;
        cout<<"LEFT DATA:";
        cin>>nodeData;
        if(nodeData==-1){
            parent->left=nullptr;
        }
        else{
            parent->left=new Node(nodeData);
            pendingNodes.push(parent->left);
        }
        cout<<"RIGHT DATA:";
        cin>>nodeData;
        if(nodeData==-1){
            parent->right=nullptr;
        }
        else{
            parent->right=new Node(nodeData);
            pendingNodes.push(parent->right);
        }
    }
    return root;
}
void printTree(Node* root){
    queue<Node*> pendingNodes;
    if(root==nullptr){
        return;
    }
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Node* parent=pendingNodes.front();
        pendingNodes.pop();
        cout<<parent->data;
        if(parent->left!=nullptr){
        cout<<"-L:"<<parent->left->data;
        pendingNodes.push(parent->left);
        }
        if(parent->right!=nullptr){
        cout<<"  R:"<<parent->right->data;
        pendingNodes.push(parent->right);
        }
        cout<<endl;
    }  
}
bool checkCousin(Node* root,int p,int q){
    vector<Node*> Layer1;
    vector<Node*> Layer2;
    bool flag1=false,flag2=false;
    if(root==nullptr||(root->data==p)||(root->data==q)){
        return false;
    }
    Layer1.push_back(root);
    while(Layer1.size()!=0 || Layer2.size()!=0){
     while(Layer1.size()!=0){
         auto itr=Layer1.begin();
         if(((*itr)->left->data==q&&(*itr)->right->data==p)||(*itr)->right->data==p&&(*itr)->right->data==q){
             return false;
         }
         Layer2.push_back((*itr)->left);
         Layer2.push_back((*itr)->right);
         Layer1.erase(itr);
     }     
    }
    flag1=binary_search(Layer2.begin(),Layer2.end(),p);
    flag2=binary_search(Layer2.begin(),Layer2.end(),q);
    if(flag1&&flag2){
        return true;
    }
    while(Layer2.size()!=0){
         auto itr=Layer2.begin();
         if(((*itr)->left->data==q&&(*itr)->right->data==p)||(*itr)->right->data==p&&(*itr)->right->data==q){
             return false;
         }
         Layer1.push_back((*itr)->left);
         Layer1.push_back((*itr)->right);
         Layer2.erase(itr);
     }     
    flag1=binary_search(Layer1.begin(),Layer1.end(),p);
    flag2=binary_search(Layer1.begin(),Layer1.end(),q);
    if(flag2&&flag1){
        return
    }
}
int main(){
    Node* root=input();
    printTree(root);
    int q,p;
    cout<<"ENTER FIRST NODE:";
    cin>>q;
    cout<<"ENTER SECOND NODE:";
    cin>>p;
    bool res=checkCousin(root,q,p);
}