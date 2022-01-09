#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int> rev(stack<int> s){
    if(s.size()==0){
        return s;
    }
    int tmp=s.top();
    s.pop();
    s=rev(s);
    // cout<<tmp<<" ";
    s.push(tmp);
    return s;
}
int main(){
    stack<int> s;
    for(int i=0;i<10;i++){
        s.push(i);
    }
    s=rev(s);
    cout<<endl;
    for(int i=0;i<10;i++){
        int tmp=s.top();
        cout<<tmp<<" ";
        s.pop();
    }
}