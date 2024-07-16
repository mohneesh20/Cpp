#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<string>> result;
bool isPal(string str){
    int l=0,r=str.size()-1;
    while(l<r){
        if(str[l++]==str[r--]) continue;
        else return false;
    }
    return true;
}
void palind(string str,int n,vector<string> tmp){
    if(str.size()==0){
        result.push_back(tmp);
        return;
    }
    for(int i=0;i<n;i++){
        string sub=str.substr(0,i+1);
        string part2sub=str.substr(i+1);
        if(isPal(sub)){
            tmp.push_back(sub);
            palind(part2sub,part2sub.size(),tmp);
            tmp.pop_back();
        }        
    }
}
int main(){
    string str="abaca";
    palind(str,str.size(),{});
    for(auto vec_str:result){
        for(auto str:vec_str){
            cout<<str<<" ";
        }
        cout<<endl;
    }
}