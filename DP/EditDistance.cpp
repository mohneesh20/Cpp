#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
int editDistance(string s,string t,vector<vector<int>> &output){
    if(s==""||t==""){
        return max(s.size(),t.size());
    }
    if(output[s.size()-1][t.size()-1]!=-1){
        return output[s.size()-1][t.size()-1];
    }
    if(s[0]==t[0]){
        return editDistance(s.substr(1),t.substr(1),output);
    }
    else{
    int a=editDistance(s.substr(1),t,output)+1;
    int b=editDistance(s,t.substr(1),output)+1;
    int c=editDistance(s.substr(1),t.substr(1),output)+1;
    output[s.size()-1][t.size()-1]=min(a,min(b,c));
    return min(a,min(b,c));
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    vector<vector<int>> output(s.size(),vector<int>(t.size(),-1));
    editDistance(s,t,output);
    cout<<output[s.size()-1][t.size()-1];
    
}