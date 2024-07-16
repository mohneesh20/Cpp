#include<bits/stdc++.h>
using namespace std;
string window(string s,string t){
    int m=s.size();
    int n=t.size();
    if(s==""||t==""||s.size()<t.size()){
        return "";
    }
    unordered_map<char,int> mp;
    for(char &c:t){
        mp[c]++;
    }
    int count=n;
    int start=0,end=0,min_len=INT32_MAX,startIndex=0;
    while(end<m){
        if(mp[s[end++]]-->0){
            count--;
        }
        while(count==0){
            if(end-start<min_len){
                min_len=end-start;
                startIndex=start;
            }
            if(mp[s[start++]]++==0){
                count++;
            }
        }
    }
    if(min_len==INT32_MAX){
        return "";
    }
    return s.substr(startIndex,min_len);
}
int main(){
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<window(s,t);
}