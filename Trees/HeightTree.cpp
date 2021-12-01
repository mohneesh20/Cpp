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
// void printTree(Tree* root){
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<":";
//     for(int i=0;i<root->children.size();i++){
//         cout<<root->children[i]->data<<",";
//     }
//     for(int i=0;i<root->children.size();i++){
//         printTree(root->children[i]);
//     }
// }
int printTree2(Tree* root){
            if(root==NULL){
            return(0);
        }
        int height=0;
        int temp;
        for(auto x:root->children){
            temp=printTree2(x);
            if(height<temp){
                height=temp;
            }
        }
        return(height+1);
}
int main(){
    Tree* root=lev();
    // printTree(root);
    int height=printTree2(root);
    cout<<"HEIGHT:"<<height;
}