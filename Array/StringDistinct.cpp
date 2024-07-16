#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int getDistinct(string s,int k){
    unordered_map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]+=1;
    }
    int ch=m.size(),max=0;
    for(int i=0;i<k;i++){
        m[s[i]]--;
        if(m[s[i]]==0){
            ch--;
        }
    }
    if(ch>max){
        max=ch;
    }
    // cout<<"MAX:"<<max<<endl;
    for(int i=1;i<2;i++){
        m[s[i-1]]++;
        if(m[s[i-1]]==1){
            ch++;
        }
        m[s[i+k-1]]--;
        if(m[s[i+k-1]]==0){
            ch--;
        }
        if(ch>max){
            max=ch;
        }
    }
    return max;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<getDistinct(s,k);

}
