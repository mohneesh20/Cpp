#include<bits/stdc++.h>
using namespace std;
void permuteSeq(int idx,int n,int k){
    if(idx==n){
        return;
    }
    int counter=1;
    for(int i=1;i<n;i++){
        counter*=i;
    }
    cout<<counter<<endl;
}
int main(){
    int n,k;
    cin>>n>>k;
    permuteSeq(0,n,k);
}