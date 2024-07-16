#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int mn=INT32_MAX;
void getSum(int idx,int n,int sum,vector<int>& heights){
    if(idx>n){
        return;
    }
    if(idx==n){
        mn=min(sum,mn);
        return;
    }
    cout<<idx<<" "<<sum<<endl;
    getSum(idx+1,n,sum+abs(heights[idx+1]-heights[idx]),heights);
    getSum(idx+2,n,sum+abs(heights[idx+2]-heights[idx]),heights);
}
int main(){
    vector<int> heights={10,20,30,10};
    getSum(0,heights.size(),0,heights);
    cout<<mn;
}