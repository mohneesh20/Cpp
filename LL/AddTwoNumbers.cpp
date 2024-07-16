#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val,Node* nxt):data(val),next(nxt){}
    Node(int val):data(val),next(nullptr){}
};
void addNumber(Node* l1,Node* l2){
    int len1=0,len2=0;
    Node *prev=l1,*cur=l1->next,*head=l1;
}
int main(){
    Node* tmp=new Node(5);
    Node *tmp2=new Node(4,tmp);
    tmp=tmp2;
    Node *head=new Node(4,tmp);
    tmp=new Node(5);
    Node *head2=new Node(4,tmp);
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
    while(head2!=nullptr){
        cout<<head2->data<<"->";
        head2=head2->next;
    }
    cout<<endl;
    addNumber(head,head2);
}