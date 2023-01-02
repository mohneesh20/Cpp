#include<iostream>
#include<vector>
using namespace std;
//18 4 16 8 23 13 20 11 28 24 26 25 1 30 15 19
void divide(int left,int right,int up,int down,vector<vector<int>> arr){
    if(left>=right){
        cout<<left<<" "<<right<<" "<<arr[0][right]<<endl;
        return;
    }
    int mid=(left+right)/2;
    cout<<left<<" "<<right<<" "<<arr[0][right]<<endl;
    divide(left,mid,up,down,arr);
    divide(mid+1,right,up,down,arr);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // divide(0,n-1,0,n-1,arr);
}