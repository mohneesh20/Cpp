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
pair<int,int> maxSum(Tree* root){
    if(root==nullptr){
        pair<int,int> y;
        return y;
    }
    pair<int,int> vals;
    vals.first=root->data;
    vals.second=root->data;
    for(auto chld:root->children){
        vals.second=vals.second+chld->data;
    }
    pair<int,int> res;
    for(int i=0;i<root->children.size();i++){
        res=maxSum(root->children[i]);
        // cout<<endl;
        // cout<<"NodeRes:"<<res.first<<" Sum:"<<res.second<<endl;
        // cout<<"NodeVals1:"<<vals.first<<" Sum:"<<vals.second<<endl;
        int sum=res.second;
        if(sum>vals.second);{
        vals.first=res.first;
        vals.second=vals.second;
        }
    }
    // cout<<"NodeVals2:"<<vals.first<<" Sum:"<<vals.second;
    cout<<endl;
    return vals;
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
    printTree2(root);
    pair<int,int> sum=maxSum(root);
    cout<<"Node:"<<sum.first<<endl<<"Sum:"<<sum.second;
}