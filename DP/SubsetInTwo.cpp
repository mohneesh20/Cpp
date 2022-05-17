#include<iostream>
using namespace std;
#include<vector>
bool getBool(vector<int> arr,int i,vector<int> f,vector<int> s){
    if(i>arr.size()){
        return false;
    }
    if(i==arr.size()){
        int s1=0,s2=0;
        for(int j=0;j<f.size();j++){
            // cout<<f[j]<<" ";
            s1+=f[j];
        }
        // cout<<endl;
        for(int j=0;j<s.size();j++){
            // cout<<s[j]<<" ";
            s2+=s[j];
        }
        // cout<<endl<<endl;
        if(s1==s2){
            return true;
        }
        else return false;
    }
    f.push_back(arr[i]);
    if(getBool(arr,i+1,f,s)){
        return true;
    }
    f.pop_back();
    s.push_back(arr[i]);
    if(getBool(arr,i+1,f,s)){
        return true;
    }
}
int main(){
    vector<int> arr = {1, 3, 5};
    bool flag=getBool(arr,0,{},{});
    cout<<flag;
}