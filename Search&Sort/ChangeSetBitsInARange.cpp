#include<iostream>
using namespace std;
int main(){
    int x=8,y=7,l=1,r=2;
    for(int i=1;i<=r;i++){
        if(i>=l){
        if(y&(1<<i-1)){
            x=x|(1<<i-1);
            }    
        }        
    }
    cout<<x;
}