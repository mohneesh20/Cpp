#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> answer;
void combinational(vector<int> arr,int sum,int chksum,vector<int> res){
    if(chksum>sum){
        return;
    }
    if(chksum==sum){
        answer.push_back(res);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(res.size()==0){
            res.push_back(arr[i]);
            combinational(arr,sum,chksum+arr[i],res);
            res.pop_back();
        }
        else{
            if(res[res.size()-1]<=arr[i]){
                res.push_back(arr[i]);
                combinational(arr,sum,chksum+arr[i],res);
                res.pop_back();
            }
        }
    }
}
int main(){
    vector<int> arr = {8,1,8,6,6,1,1,1,8};
    int sum;
    cout<<"Enter Sum:";
    cin>>sum;
    sort(arr.begin(),arr.end());
    for(auto itr=arr.begin();itr!=arr.end();itr++){
        auto prev=itr-1;
        if(*itr==*prev){
            arr.erase(itr);
            itr--;
        }
    }
    combinational(arr,sum,0,{});
    for(auto y:answer){
        for(auto x:y){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
