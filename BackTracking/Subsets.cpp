#include<iostream>
#include<vector>
using namespace std;
void subset(vector<int> arr,vector<int> sub,int idx){
    if(idx==arr.size()){
        cout<<"SUBSET:";
        for(auto x:sub){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    subset(arr,sub,idx+1);
    sub.push_back(arr[idx]);
    subset(arr,sub,idx+1);
}
int main(){
    vector<int> arr={1,2,3};
    subset(arr,{},0);
}