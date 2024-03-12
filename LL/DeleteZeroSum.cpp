#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class UDD{
    public:
    int a=-1;
    int b=-1;
};
//1 2 -3 3 1 5
ListNode* removeZeroSumSublists(ListNode* head) {
    int cnt=0,count=0;
    int prefix=0;
    ListNode* head2,*tmp;
    tmp=head;
    unordered_map<int,UDD> mp;
    while(tmp!=nullptr){
        prefix+=tmp->val;
        if(prefix==0){
            count=cnt+1;
            head2=tmp->next;
        }
        if(mp[prefix].a==-1){
            mp[prefix].a=cnt;
        }else{
            mp[prefix].b=cnt;
        }
        cnt++;
        tmp=tmp->next;        
    }
    return head2;
}
int main(){
    ListNode* head=nullptr,*tmp,*prev=nullptr;
    int sz=3;
    for(int i=0;i<sz;i++){
        int nde_val;
        cin>>nde_val;
        tmp=new ListNode(nde_val);
        if(prev!=nullptr){
            prev->next=tmp;
        }
        prev=tmp;
        if(head==nullptr) head=tmp;        
    }
   head=removeZeroSumSublists(head);
   while(head!=nullptr){
    cout<<head->val<<" ";
    head=head->next;
   }

}