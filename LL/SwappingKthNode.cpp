#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 void swapKthNode(ListNode *head,int k){
    int l=0;
    ListNode* tmp=head;
    while(tmp!=nullptr){
        tmp=tmp->next;
        l++;
    }
    tmp=head;
    int index1=1;
    bool flag=false;
    ListNode* node1;
    // cout<<k<<" "<<(l+1-(k))<<endl<<endl;
    while(tmp!=nullptr){
        int index2=l-index1+1;        
        if(k==index1 || k==index2){ 
            if(!flag){
                node1=tmp;
                // cout<<node1->val<<endl;
                flag=true;
            }
            else{
                int tmp_val=node1->val;
                node1->val=tmp->val;
                tmp->val=tmp_val;
            }
        }
        tmp=tmp->next;
        index1++;
    }
 }
 int main(){
    ListNode *tmp,*head;
    head=new ListNode(1);
    tmp=head;
    int n=10,k=1;
    int i=1;
    n--;
    while(n!=0){
        ListNode *tmp2=new ListNode(++i);
        tmp->next=tmp2;
        tmp=tmp2;
        n--;
    }
    tmp=head;
    swapKthNode(head,k);
    while(tmp!=nullptr){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
 }