#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> A,int start,int mid,int end){
    vector<int> temp;
    // temp.reserve(end-start-1);
    int i=start,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(A[i]<=A[j]){
            temp[k++]=A[i++];
        }
        else{
            temp[k++]=A[j++];
        }
        while(i<=mid){
            temp[k++]=(A[i++]);
        }
        while(j<=end){
            temp[k++]=(A[j++]);
        }
        for(i=start;i<=end;i++){
            A[i]=temp[i-start];
        }
    }
}
void mergeSort(vector<int> A,int start,int end){
    if(start<end){
        int mid=(start+mid)/2;
        mergeSort(A,start,mid);
        mergeSort(A,mid+1,end);
        merge(A,start,mid,end);
    }
}
int main(){
    vector<int> V{-5,20,10,3,2,0};
    mergeSort(V,0,V.size()-1);
    for(auto x:V){
        cout<<x<<' ';
    }
}