#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
//1 4 3 2 5 2 3
Node* partList(Node* head,int x){
    bool flag=false;
    Node* left=head,*right=head;
    while(left->data!=x&&right!=nullptr){
       if(!flag){
            if(right->data!=x){
                right=right->next;
            }
            else{
                left=left->next;
                if(left->data>right->data){
                    int temp=right->data;
                    right->data=left->data;
                    left->data=temp;
                    right=left;
                    flag=true;
                }
            }
       }
       else{
        if(left)
       }      
    }
    return head;
}
int main(){
    Node* head,*temp;
    temp=new Node(3);
    temp=new Node(2,temp);
    temp=new Node(5,temp);
    temp=new Node(2,temp);
    temp=new Node(3,temp);
    temp=new Node(4,temp);
    temp=new Node(1,temp);
    head=temp;
    int x=3;
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    head=temp;
    cout<<endl;
    head=partList(head,x);
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
}