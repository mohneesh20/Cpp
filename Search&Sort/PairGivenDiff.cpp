#include <iostream>
#include<vector>
using namespace std;
void getVal(vector<int> arr,int k,int sum,int &val,int i,int j,int m){
    if(i>j){
        return;
    }
    if(k==0){
        // cout<<sum<<" ";
        if(val<sum){
            val=sum;
        }
        return;
    }
    for(int m=i;m<j;m++){
        getVal(arr,k-1,sum+arr[m],val,m+1,j,m);
        getVal(arr,k-1,sum+arr[m],val,i,m-1,m);
    }
}
int main() {
    vector<int> arr={4,6,10,1,10,20};
    int n=arr.size();
    int k=4;
    int val=INT32_MIN;
    getVal(arr,k,0,val,0,n,0);
    cout<<val;
}
