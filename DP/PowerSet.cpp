#include<iostream>
#include<string>
using namespace std;
void printSubsequence(string s){
    int n=s.size();
    for(int num=0;num<(1<<n);num++){
        string sub="";
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                sub+=s[i];
            }
        }
        cout<<sub<<endl;
    }
}
int main(){
    string s="abcd";
    printSubsequence(s);
}