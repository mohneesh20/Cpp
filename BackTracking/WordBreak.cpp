#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> str;
void permute(int idx,vector<bool> visited,string s,int n,vector<string> dic,string Str,string chkStr){
    if(chkStr.size()>s.size()){
        return;
    }
    if(chkStr==s){
        Str=Str.substr(0,Str.size()-1);
        str.push_back(Str);
        return;
    }
    if(idx==n){
        return;
    }
    for(int i=0;i<n;i++){
        permute(idx+1,visited,s,n,dic,Str,chkStr);
        if(visited[i]==false){
            visited[i]=true;
            permute(idx+1,visited,s,n,dic,Str+s[i]+" ",chkStr+s[i]);
            visited[i]=false;
        }
    }
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> dic={"apple","pen","applepen","pine","pineapple"};
    vector<bool> visited(n,false);
    permute(0,visited,s,n,dic,"","");
    for(auto x:str){
        cout<<x<<endl;
    }
}