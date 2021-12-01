#include<iostream>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* rev(ListNode* head){
    if(head->next==nullptr){
        return head;
    }
    ListNode *temp=rev(head->next);
    // cout<<head->val<<"->";
    head->next->next=head;
    head->next=nullptr;
    return temp;
}
int main(){
    ListNode *tmp,*head;
    tmp=new ListNode(10);
    tmp=new ListNode(9,tmp);
    tmp=new ListNode(8,tmp);
    tmp=new ListNode(7,tmp);
    tmp=new ListNode(6,tmp);
    tmp=new ListNode(5,tmp);
    tmp=new ListNode(4,tmp);
    tmp=new ListNode(3,tmp);
    tmp=new ListNode(2,tmp);
    tmp=new ListNode(1,tmp);
    ListNode *temp=rev(tmp);
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
}