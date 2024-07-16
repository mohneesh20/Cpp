#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dif=INT32_MAX;
int getMinDiff(vector<int> arr,int size,int counter,int min,int max,int k){
    sort(arr.begin(),arr.end());
    int ans=arr[size-1]-arr[0];
    int maxH,minH;
    for(int i=1;i<size;i++){
        maxH=std::max(arr[size-1]-k,arr[i-1]+k);
        minH=std::min(arr[size-1]+k,arr[i-1]-k);
        if(minH<0){
            continue;
        }
        ans=std::min(ans,maxH-minH);
    }
    return ans;
}
int main(){
    vector<int> arr={1, 5, 8, 10};
    int n=arr.size();
    int k=2;
    cout<<getMinDiff(arr,n,0,INT32_MIN,INT32_MAX,k);
}
