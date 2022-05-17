#include<iostream>
#include<string>
using namespace std;
int sum(int n){
    if(n==1){
        return n;
    }
    n=n+sum(n-1);
    return n;
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
}