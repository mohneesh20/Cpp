#include<iostream>
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
    int number;
    cin>>number;
    cout<<Fib(number);
}