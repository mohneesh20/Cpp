// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<vector<int>> arr={
        {1,2,0},
        {4,1,3},
        {3,2,2},
        {1,4,1},
    };
    int timer=0;
    vector<int> result;
    // vector<int> result(arr.size(),0);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
    }
    while(pq.size()!=0){
        auto tmp=pq.top();
        if(timer<tmp[0]){
            timer++;
        }
        else{
            cout<<timer<<endl;
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq2;
            while(timer>=tmp[0]){
                cout<<tmp[0]<<endl;
                pq2.push(tmp);
                pq.pop();
                if(pq.size()!=0){
                    tmp=pq.top();
                }
            }
        }
    }
}