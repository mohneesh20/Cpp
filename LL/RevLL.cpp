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
ListNode* rev(ListNode* head,int k){
    if(head->next==nullptr){
        return head;
    }
    
}
// ListNode* comp(ListNode* head){
//     ListNode* tmp=head;
//     while(head->next->next!=nullptr){
//         head=head->next;
//     }
//     head->next->next=tmp;
//     tmp=head->next;
//     head->next=nullptr;
//     return tmp;
// }
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
    ListNode* tep=tmp;
    int k=2;
    ListNode *temp=rev(tmp,k);

}