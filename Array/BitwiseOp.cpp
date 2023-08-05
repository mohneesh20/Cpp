#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=4,b=2,c=7;
    // int num=8;
    int counter=0;
    string as="",bs="",cs="";
    while((a!=0)||(b!=0)||(c!=0)){

        int chk1=(int)(a&1);
        // if(chk1==1){
        //     as=as+'1';
        // }
        // else{
        //     as=as+'0';
        // }
        a=(a>>1);
        int chk2=b&1;
        // if(chk2==1){
        //     bs=bs+'1';
        // }
        // else{
        //     bs=bs+'0';
        // }
        b=(b>>1);
        int chk3=c&1;
        // if(chk3==1){
        //     cs=cs+'1';
        // }
        // else{
        //     cs=cs+'0';
        // }
        c=(c>>1);
        if((chk1|chk2)==chk3) continue;
        else{
            if(chk1!=chk2 || ((chk1==chk2)&&(chk1==0))) counter++;
            else counter+=2;
        }
    }
    cout<<counter<<endl; 
}