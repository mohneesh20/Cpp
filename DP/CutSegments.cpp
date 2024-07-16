#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getCount(int* arr,int i,int n,int sum,int counter,int* mx){
    if(sum>n){
        return;
    }
    if(sum==n){
        if(*mx<counter){
            *mx=counter;
        }
        return;
    }
    getCount(arr,0,n,sum+arr[0],counter+1,mx);
    getCount(arr,1,n,sum+arr[1],counter+1,mx);
    getCount(arr,2,n,sum+arr[2],counter+1,mx);
}
int main(){
    int n=5,x=5,y=3,z=2;
    int arr[3];
    arr[0]=x;
    arr[1]=y;
    arr[2]=z;
    sort(arr,arr+3);
    int mx=0;
    getCount(arr,0,n,0,0,&mx);
    cout<<mx;
}