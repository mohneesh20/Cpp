#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int minSum=INT32_MAX;
vector<int> a;
vector<int> b;
void subsets(vector<bool> visited,vector<int> arr,int n,vector<int> set,int idx,int cur,int totSum){
    if(set.size()==(n/2)){
        int resSum=totSum-cur;
        if(abs(resSum-cur)<minSum){
            minSum=abs(resSum-cur);
            a.clear();
            b.clear();
            for(int i=0;i<n;i++){
                if(visited[i]==true){
                    a.push_back(arr[i]);
                }
                else{
                    b.push_back(arr[i]);
                }
            }
        }
    }
    if(idx==n){
        return;
    }
    subsets(visited,arr,n,set,idx+1,cur,totSum);
    set.push_back(arr[idx]);
    visited[idx]=true;
    subsets(visited,arr,n,set,idx+1,cur+arr[idx],totSum);
}
int main(){
    vector<int> arr={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n=arr.size();
    int sum=0;
    for(auto x:arr){
        sum+=x;
    }
    vector<bool> visited(n,false);
    subsets(visited,arr,n,{},0,0,sum);
    for(auto x:a){
        cout<<x<<' ';
    }
    cout<<endl;
    for(auto x:b){
        cout<<x<<' ';
    }
}