#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={2, 3, 4, 5, -1, 0};
    int n=arr.size();
    int cur_pro=1;
    int max_pro=INT32_MIN;
    for(int i=0;i<n;i++){
        cur_pro*=arr[i];
        max_pro=std::max(cur_pro,max_pro);
        if(cur_pro==0){
            cur_pro=1;
        }
    }
    cur_pro=1;
    int maxx_pro=INT32_MIN;
    for(int i=n-1;i>=0;i--){
        cur_pro*=arr[i];
        maxx_pro=std::max(cur_pro,maxx_pro);
        if(cur_pro==0){
            cur_pro=1;
        }
    }
    cout<<std::max(max_pro,maxx_pro);
}