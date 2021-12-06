#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void permute(string nums,int str,int len){
        if(str==len){
            cout<<nums<<endl;
            // answer.push_back(nums);
            return;
        }
        for(int i=str;i<len;i++){
            swap(nums[str],nums[i]);
            permute(nums,str+1,len);
            swap(nums[str],nums[i]);
        }
    }
int main(){
    string s;
    cout<<"Enter String:";
    cin>>s;
    int len=s.size();
    permute(s,0,len);
}