#include<iostream>
#include<string>
#include"OurMap.h"
using namespace std;
int main(){
    ourMap<int> map;
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<" ";
    }
    cout<<endl;
    map.remove("abc7");
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":"<<map.getValue(key)<<" ";
    }
    cout<<endl<<map.size();
}