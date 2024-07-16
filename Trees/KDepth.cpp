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
void printKNodes(Tree* root,int k){
    if(k==0){
        cout<<root->data;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printKNodes(root->children[i],k-1);
    }
}
int main(){
    Tree* root=lev();
    // printTree(root);
    cout<<"ENTER THE DEPTH:";
    int k;
    cin>>k;
    cout<<endl;
    printKNodes(root,k);
}