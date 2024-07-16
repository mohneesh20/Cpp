#include<iostream>
#include<queue>
using namespace std;
class Tree{
    public:
    int data;
    vector<Tree*> children;
    Tree(int x):data(x){};
};
Tree* lev(){
    cout<<"ENTER ROOT DATA:";
    int rootData;
    cin>>rootData;
    cout<<endl;
    Tree *root=new Tree(rootData);
    queue<Tree*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Tree* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"ENTER NUMBER OF CHILDREN:";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int childData;
            cin>>childData;
            Tree* child=new Tree(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }

    }
    return root;
}
void printTree(Tree* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
void printTree2(Tree* root){
    if(root==NULL){
        return;
    }
    queue<Tree*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        Tree* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<"->";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int main(){
    Tree* root=lev();
    // printTree(root);
    printTree2(root);
}