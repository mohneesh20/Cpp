#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    int minv;
    Node* next=nullptr;
    Node(int x,Node* next,int y):data(x),next(next),minv(y){}
};
class Stk{
    Node* head=nullptr;
    public:
    void push(int x){
        if(head==nullptr){
            head=new Node(x,nullptr,x);
            head->minv=x;
        }
        else{
            head=new Node(x,head,min(x,head->minv));
        }
    }
    int top(){
        if(head==nullptr){
            return -1;
        }
        else{
            return head->data;
        }
    }
    void print(){
        Node* tmp=head;
        while(tmp!=nullptr){
            cout<<tmp->data<<":"<<tmp->minv<<endl;
            tmp=tmp->next;
        }
    }
    void pop(){
        if(head==nullptr){
            return;
        }
        else{
            Node* tmp=head;
            head=head->next;
            delete(tmp);
        }
    }
};
int main(){
    Stk v;
    v.push(7);
    v.push(6);
    v.push(5);
    v.push(6);
    v.push(3);
    // cout<<v.top()<<endl;
    // v.pop();
    // cout<<v.top()<<endl;
    v.print();
}