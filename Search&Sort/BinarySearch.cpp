#include<bits/stdc++.h>
using namespace std;
int b_search(vector<int>& arr,int l,int r,int f){
   while(l<=r){
    int mid=(l+r)/2;
    if(arr[mid]>f){
        r=mid-1;
    }
    if(arr[mid]==f){
        return mid;
    }
    if(arr[mid]<f){
        l=mid+1;
    }
   }
   return -1;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int f;
    cin>>f;
    cout<<b_search(arr,0,arr.size()-1,f);
}