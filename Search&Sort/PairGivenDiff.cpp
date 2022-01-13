#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n = 5, k = 45;
    vector<int> arr = {90, 70, 20, 80, 50};
    sort(arr.begin(),arr.end());
    auto strt=arr.begin();
    auto nd=arr.end()-1;
    if(*nd<k){
        cout<<"NONE";
        return 0;
    }
    while(strt<nd){
        int diff=*nd-*strt;
        if(diff==k){
            cout<<*strt<<" "<<*nd;
            return 0;
        }
        if(diff>k){
            strt++;
        }
        else{
            nd--;
            strt=arr.begin();
        }
    }
    cout<<"NONE";
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
}