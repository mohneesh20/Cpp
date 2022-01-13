#include<iostream>
#include<vector>
using namespace std;
int steps=INT32_MAX;
bool MinSteps(vector<int> arr,int distance,int counter,int idx){
    if(idx>=arr.size()){
        return false;
    }
    // cout<<idx<<" ";
    distance+=arr[idx];
    cout<<distance<<"-"<<counter<<" ";
    if(distance>=arr.size()){
        if(counter<steps){
            // cout<<counter<<" ";
            steps=counter;
        }
        return true;
    }
    for(int i=0;i<arr[idx];i++){
        MinSteps(arr,distance,counter+1,idx+arr[i]);
    }
    return false;
}
int main(){
    vector<int> arr={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    MinSteps(arr,0,0,0);
    if(steps==INT32_MAX){
        cout<<"NOT POSSIBLE";
    }
    else{
        cout<<endl<<steps;
    }
}