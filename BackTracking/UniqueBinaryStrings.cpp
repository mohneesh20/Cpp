#include <iostream>
#include <vector>
#include <string>
using namespace std;
string num="";
bool findNum(vector<string> nums,int idx,string str){
    if(idx==nums.size()){
        for(auto x:nums){
            if(x==str){
                return false;
            }
        }
        num=str;
        return true;
    }
    if(findNum(nums,idx+1,str+"0")==true){
        return true;
    }
    if(findNum(nums,idx+1,str+"1")==true){
        return true;
    }
    return false;
}
int main()
{
    vector<string> nums = {"00","11"};
    findNum(nums,0,"");
    cout<<num;
}