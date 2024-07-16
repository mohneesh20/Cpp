#include<iostream>
#include<queue>
#include<vector>
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
bool identical(Tree* root1,Tree* root2){
    if(root1==nullptr||root2==nullptr){
        return false;
    }
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    else{
        for(int i=0;i<root1->children.size();i++){
            bool flag=identical(root1->children[i],root2->children[i]);
            
        }
        if(root1->data==root2->data){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    Tree* root=lev();
    Tree* root2=lev();
    bool result=identical(root,root2);
}