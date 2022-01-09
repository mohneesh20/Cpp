#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr={5, 3, 2, 4, 1};
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+i*arr[i];
    }
    cout<<sum;
}