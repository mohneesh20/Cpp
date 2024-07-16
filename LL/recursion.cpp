#include<iostream>
#include<string>
using namespace std;
string rev(string name){
    if(name==""){
        return "";
    }
    string res=rev(name.substr(1));
    res=res+name[0];
    return res;
}
int main(){
    string name;
    cin>>name;
    name=rev(name);
    cout<<name;
}
