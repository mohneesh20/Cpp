#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
bool isPrime(int n){
    if(n==2||n==3||n==1){
        return true;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
map<int,int> getArr(int maxEle){
    map<int,int> mp;
    for(int i=1;i<maxEle;i++){
        if(mp[i]==0){
            if(isPrime(i)){
                mp[i]=true;
            }
            else{
                int num=i;
                int counter=1;
                while(num*counter<=maxEle){
                    // cout<<num*counter<<" ";
                    mp[num*counter]=-1;
                    counter++;
                }
                // cout<<endl;
            }
        }
    }
    return mp;    
}
int main(){
    int maxNum;
    cin>>maxNum;
    map<int,int> mp=getArr(maxNum);
    map<int,int> mp=getArr2(maxNum);
    // for(auto itr:mp){
    //     cout<<itr.first<<" "<<itr.second<<endl;
    // }
}