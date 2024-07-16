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
ListNode* revK(ListNode* head,int k){
    if(head==nullptr&&head->next==nullptr){
        return head;
    }
    ListNode* prev=head,*curr=head->next;
    for(int i=0;i<k-1;i++){
    ListNode* temp=curr->next;
    prev=curr;
    curr=temp;
    }
    return prev;
}
ListNode* revKList(ListNode* head,int k){
    if(head==nullptr&&head->next==nullptr){
        return head;
    }
    ListNode* temp=head;
    int l=0;
    while(temp!=nullptr){
        temp=temp->next;
        l++;
    }
    ListNode *prev=head,*curr=head->next;
    for(int i=0;i<k-1;i++){
    ListNode* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    }
    l-=k;
    while(l>=k){
        ListNode* prev2=curr;
        ListNode* head2=curr;
        curr=prev2->next;
        for(int i=0;i<k-1;i++){
            ListNode* temp=curr->next;
            curr->next=prev2;
            prev2=curr;
            curr=temp;
        }
        l-=k;
        head->next=prev2;
        head=head2;
    }       
    if(curr!=nullptr){
    head->next=curr;
    }
    else{
    head->next=nullptr;
    }
    return prev;
}
void iterate(ListNode* head){
    ListNode* i1=head;
    ListNode* i2=head->next;
    while(i1->val!=i2->val){
        i1=i1->next;
        i2=i2->next->next->next;
    }
    cout<<i2->val;

}
int main(){
    ListNode *tmp,*head,*tail;
    tmp=new ListNode(26);
    tail=tmp;
    int i=25;
    while(i!=0){
    tmp=new ListNode(i,tmp);
    i--;
    }
    head=tmp;
    tail->next=head;
    iterate(head);
}