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
class resultData{
    public:
    int sum=0;
    vector<int>* output=nullptr;
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
resultData LongestLeafToRoot(Node* root){
    if(root==nullptr){
        resultData r;
        return r;
    }
    vector<int>* res=new vector<int>();
    resultData left;
    resultData right;
    if(root->left!=nullptr){
        left=LongestLeafToRoot(root->left);
    }
    if(root->right!=nullptr){
        right=LongestLeafToRoot(root->right);
    }
    if(left.output==nullptr&&right.output==nullptr){
    res->push_back(root->data);
    resultData result;
    result.output=res;
    result.sum=root->data;
    return result;
    }
    if(left.output==nullptr){
        right.output->push_back(root->data);
        resultData result;
        result.output=right.output;
        result.sum=right.sum+root->data;
        return result;
    }
    if(right.output==nullptr){
        left.output->push_back(root->data);
        resultData result;
        result.output=left.output;
        result.sum=left.sum+root->data;
        return result;
    }
    if(left.output->size()>right.output->size()){
        left.output->push_back(root->data);
        resultData result;
        result.output=left.output;
        result.sum=left.sum+root->data;
        return result;
    }
    else{
        right.output->push_back(root->data);
        resultData result;
        result.output=right.output;
        result.sum=right.sum+root->data;
        return result;
    }
}
int main(){
    Node* root=takeLevelInput();
    printTree(root);
    resultData result=LongestLeafToRoot(root);
    cout<<endl;
    for(int i=0;i<result.output->size();i++){
        cout<<result.output->at(i)<<" ";
    }
    cout<<endl<<result.sum;
}