#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next=nullptr;
    Node* prev=nullptr;
    Node(int x):data(x),next(nullptr),prev(nullptr){}
    Node(int x,Node* next,Node* prev):data(x),next(next),prev(prev){}
};
class Stk{
    public:
    Node* head=nullptr;
    Node* mid=nullptr;
    int size=0;
    void push(int x){
        if(head==nullptr){
            head=new Node(x);
            mid=head;
        }
        else{
            head=new Node(x,nullptr,head);
            Node* tmp=head->prev;
            tmp->next=head;
            if(size%2==1){
                mid=mid->next;
            }
        }
        size++;
    }
    void pop(){
        if(head==nullptr){
            return;
        }
        else{
            Node *tmp=head;
            head=head->prev;
            if(size%2==1){
                mid=mid->prev;
            }
            delete tmp;
        }
        size--;
    }
    void print(){
        Node* tmp=head;
        while(tmp!=nullptr){
            cout<<tmp->data<<":"<<mid->data<<endl;
            tmp=tmp->prev;
        }
    }
};
int main(){
    Stk s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    cout<<endl;
    s.print();
    s.pop();
    cout<<endl;
    s.print();
}