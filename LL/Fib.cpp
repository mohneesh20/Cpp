#include<bits/stdc++.h>
using namespace std;
int Fib(int n){
    if(n==0||n==1){
        if(!n)
        cout<<n<<' ';
        return n;
    }
    int k=Fib(n-1)+Fib(n-2);
    cout<<k<<' ';
    return k;

}
int main(){
    string str_number;
    cin>>str_number;
    int n=str_number.size();
    int mult=0.1;
    int number=0;
    for(int i=0;i<n;i++){
        number=number*10+(int)(str_number[i]-'0');
    }
    cout<<endl<<number;
    // cout<<((int)(number-'0'));
    // cout<<Fib(number);
}