// bombs = {{2,1,3},{6,1,4}}
#include<bits/stdc++.h>
using namespace std;
int main(){
    // vector<vector<int>> bombs={{2,1,3},{6,1,4}};
    vector<vector<int>> bombs={{54,95,4},{99,46,3},{29,21,3},{96,72,8},{49,43,3},{11,20,3},{2,57,1},{69,51,7},{97,1,10},{85,45,2},{38,47,1},{83,75,3},{65,59,3},{33,4,1},{32,10,2},{20,97,8},{35,37,3}};
    sort(bombs.begin(),bombs.end());
    bool flag=false;
    int counter=1,mx_counter=INT32_MIN;
    for(int i=0;i<bombs.size()-1;i++){
        vector<int> bomb1=bombs[i];
        vector<int> bomb2=bombs[i+1];
        long long x_sq=(bomb2[0]-bomb1[0])*(bomb2[0]-bomb1[0]);
        long long y_sq=(bomb2[1]-bomb1[1])*(bomb2[1]-bomb1[1]);
        long long r_sq=(bomb2[2]+bomb1[2])*(bomb2[2]+bomb1[2]);
        if(r_sq>=(x_sq+y_sq)){
            // cout<<i<<" "<<i+1<<" Bomb in range"<<endl;
            if(!flag){
                flag=true;
            }
            counter++;
        }
        else{
            if(flag){
                flag=false;
                mx_counter=max(mx_counter,counter);
            }
            counter=1;
        }
    }
    if(flag==true) mx_counter=max(mx_counter,counter);
    if(mx_counter==INT32_MIN){
        mx_counter=1;
    }
    cout<<mx_counter<<endl;
}