#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr={1, 2, 4, 8};
    sort(arr.begin(),arr.end());
    int sum=0;
    int l=0,r=n-1;
    while(l<r){
        cout<<arr[r]<<" "<<arr[l]<<endl;
        sum=sum+arr[r]-arr[l];
        l++;
        r--;
    }
    cout<<sum;
}