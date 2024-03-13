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
    int cnt=0,count=0;
    int prefix=0;
    ListNode* head2=head,*tmp;
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
    if(prefix==0) {
        return nullptr;
    }
    unordered_map<int,int> mp2;
    for(int i=count;i<cnt;i++){
        if(mp[i].a!=-1&&mp[i].b!=-1){
            mp2[mp[i].a]=mp[i].b;
        }
    }
    tmp=head2;
    while(tmp&&tmp->next!=nullptr){
        int skip=mp2[count];
        if(skip==0){
            tmp=tmp->next;
            count++;
        }else{
            ListNode* tmp2=tmp;
            while(count<skip){
                tmp2=tmp2->next;
                count++;
            }
            tmp->next=tmp2->next;
            count++;
            tmp=tmp->next;
        }
    }

    return head2;
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