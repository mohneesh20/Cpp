#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Bin(vector<int> A,int left,int right,int num){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(num==A[mid]){
        return mid;
    }
    if(num<A[mid]){
        return Bin(A,left,mid-1,num);
    }
    else{
        return Bin(A,mid+1,right,num);
    }
}
int main(){
    vector<int> A{-1,0,1,2,3,4,5,6};
    int num;
    cin>>num;
    cout<<Bin(A,0,A.size(),num);    
}
