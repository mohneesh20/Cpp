#include<queue>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
queue<int> revK(queue<int> q,int k,int n){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<n-k;i++){
        int tmp=q.front();
        q.pop();
        q.push(tmp);
    }
    return q;
}
int main(){
    int n=5,k=3;
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    q=revK(q,k,n);
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}