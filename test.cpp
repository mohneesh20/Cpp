#include<bits/stdc++.h>
using namespace std;
string dfs(int idx,string& s){
    // int idx=0;
    // int n=s.size();
    // string str="";
    // while(idx<n){
    //     if(s[i]=='('){
    //         str+=dfs(i+1,s);
    //         i+=str.size()+1;
    //     }else{
    //         if(s[i]==')') break;
    //     }else str+=s[i];
    // }
    // int l=0,r=str.size()-1;
    // while(l<r){
    //     swap(str[l++],str[r--]);
    // }
    // return str; 
    return "evol";
}
string reverseParentheses(string s) {
    int idx=0;
    int n=s.size();
    string str="";
    while(idx<n){
        if(s[idx]=='('){
            str+=dfs(idx+1,s);
            idx+=str.size()+1;
        }else{
            if(s[idx]==')') break;
            else str+=s[idx];
        }
        idx++;
    }
    int l=0,r=str.size()-1;
    while(l<r){
        swap(str[l++],str[r--]);
    }
    cout<<str;
    return str;
}
int main(){
    string s="(u(love)i)";
    // string s="(ed(et(oc))el)";
    s=reverseParentheses(s);
    cout<<endl<<s;
}