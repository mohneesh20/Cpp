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
//1 2 -3 3 1
ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        mp[0]=dummy;
        int prefix=0;
        ListNode* current=head;
        while(current!=nullptr){
            prefix+=current->val;
            if(mp[prefix]==0){
                mp[prefix]=current;
                current=current->next;
            }else{
                ListNode* prev=mp[prefix]->next;;
                int tmpSum=prefix;
                while(prev!=current){
                    tmpSum+=prev->val;
                    mp.erase(tmpSum);
                    prev=prev->next;
                }
                mp[prefix]->next=current->next;
                current=current->next;
            }
        }
        return dummy->next;
}
int main(){
    ListNode* head=nullptr,*tmp,*prev=nullptr;
    int sz;
    cin>>sz;
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