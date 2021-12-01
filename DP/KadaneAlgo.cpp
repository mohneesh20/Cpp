#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"ENTER LENGTH:";
    int n;
    bool flag=false;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int curr=0,max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            flag=true;
        }
        curr+=arr[i];
        if(curr<0){
            curr=0;
        }
        if(curr>max){
            max=curr;
        }
    }
    if(!flag){
        max=arr[0];
        for(int i=0;i<n;i++){
            if(max<arr[i]){
                max=arr[i];
            }
        }
    }
    cout<<max;
    delete [] arr;
}