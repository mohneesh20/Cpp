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
int printNumber(Tree* root){
    int num=1;
    for(int i=0;i<root->children.size();i++){
        num+=printNumber(root->children[i]);
    }
    if(root->children.size()==0){
        num++;
    }
    else{
        num--;
    }
    return num;
}
int main(){
    Tree* root=lev();
    // printTree(root);
    int number=printNumber(root);
    cout<<number;
}