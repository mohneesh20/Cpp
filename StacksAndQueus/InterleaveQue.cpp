#include<iostream>
#include<vector>
#include<queue>
using namespace std; 
int main(){
    queue<int> q;
    queue<int> s;
    queue<int> v;
    for(int i=11;i<=20;i++){
        q.push(i);
    }
    int hf=q.size()/2;
    for(int i=0;i<hf;i++){
        s.push(q.front());
        q.pop();
    }
    while(q.size()!=0){
        v.push(s.front());
        s.pop();
        v.push(q.front());
        q.pop();
    }
    while(s.size()!=0){
        v.push(s.front());
        s.pop();
    }
    while(v.size()!=0){
        cout<<v.front()<<' ';
        v.pop();
    }
}