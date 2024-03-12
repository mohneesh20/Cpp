#include<bits/stdc++.h>
using namespace std;
void mergeSort(int l,int mid,int r,string& s,unordered_map<char,int>& mp){
    vector<int> temp(r+1,0);
    int i=l,j=mid+1;
    int k=0;
    while(i<=mid&&j<=r){
        if(s[i]<=s[j]){
            temp[k]=s[i];
            i++;
            k++;
        }else{
            temp[k]=s[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=s[i];
        k++;
        i++;
    }
    while(j<=r){
        temp[k]=s[i];
        k++;
        j++;
    }
    i=l,j=0;
    while(i<=r){
        s[i]=temp[j];
        i++;
        j++;
    }
}
void merge(int l,int r,string& s,unordered_map<char,int>& mp){
    if(l==r){
    // cout<<s[l]<<endl;
        return;
    }
    int mid=(l+r)/2;
    merge(l,mid,s,mp);
    merge(mid+1,r,s,mp);
    mergeSort(l,mid,r,s,mp);
}
string customSortString(string order, string& s) {
        unordered_map<char,int> mp;
        for(int i=0; i<order.size(); i++) {
            mp[order[i]] =i;
        }
        merge(0,s.size()-1,s,mp);
        return s;
}
int main(){
    string order="cba";
    string s="bcda";
    // vector<int> v={1,2,3,4,1,2,3,};
    // int l=0,r=v.size()-1;
    // int mid=(l+r)/2;
    // int i=l,j=mid+1;
    // vector<int> temp;
    // while(i<=mid&&j<=r){
    //     if(v[i]<=v[j]){
    //         temp.push_back(v[i]);
    //         i++;
    //     }else{
    //         temp.push_back(v[j]);
    //         j++;
    //     }
    // }
    // while(i<=mid){
    //     temp.push_back(v[i]);
    //     i++;
    // }
    // while(j<=r){
    //     temp.push_back(v[j]);
    //     j++;
    // }
    // for(auto &itr:temp){
    //     cout<<itr<<" ";
    // }
    customSortString(order, s);
    cout<<s<<endl;   
}