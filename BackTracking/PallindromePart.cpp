#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isPal(string sub){
    int l=0,r=sub.size()-1;
    while(l<r){
        if(sub[l]!=sub[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void partPal(string s,int n,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        string sub=s.substr(0,i+1);
        cout<<sub<<" "<<s.substr(i+1)<<endl;
        // if(isPal(sub)==true){
        //     partPal(s.substr(i+1),n-1,ans+sub+" ");
        // }
    }
}
int main(){
    string str;
    cin>>str;
    partPal(str,str.size(),"");
}