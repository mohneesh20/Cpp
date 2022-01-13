#include<iostream>
using namespace std;
bool getSum(int A[],int n,int idx,int k,int sum,int count){
    if(count==2){
        if(sum==k){
        return true;
        } 
        else{
        return false;
        } 
    }
    for(int i=idx+1;i<n;i++){
        if(getSum(A,n,i,k,sum+A[i],count+1)){
            return true;
        }       
    }
    return false;
}
int main(){
    int A[]={1,2,3,5,6};
    int n=5,X=10;
    for(int i=0;i<n;i++){
        if(getSum(A,n,i,X,A[i],0)){
            cout<<"TRUE";
            return 0;
        }
    }
    cout<<"FALSE";
}