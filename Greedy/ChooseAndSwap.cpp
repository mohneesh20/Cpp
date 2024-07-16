#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s="ccad";
    int k=0;
    while(1){
    int n1=s[k]-97;
        if(n1==k){
            k++;
            n1++;
        }
        else{
            break;
        }
    }
    int min=INT32_MAX;
    if(s.size()==1){
        return s;
    }
    for(int i=k;i<s.size();i++){
        int num=s[i]-97;
        if(num<min){
            min=num;
        }
    }
    for(int i=0;i<s.size();i++){
        int num=s[i]-97;
        if(num==n1){
            s[i]=(char)(min+97);
        }
        if(num==min){
            s[i]=(char)(n1+97);
        }
    }
    cout<<s;
}