#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<int> rev(queue<int> q){
    if(q.size()==0){
        return q;
    }
    int tmp=q.front();
    q.pop();
    q=rev(q);
    q.push(tmp);
    return q;
}
int main(){
    queue<int> q;
    for(int i=0;i<10;i++){
        q.push(i);
    }
    q=rev(q);
    for(int i=0;i<10;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}