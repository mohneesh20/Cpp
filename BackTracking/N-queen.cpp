#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result;
bool isSafe(int **arr,int x,int y,int n){
    for(int k=0;k<n;k++){
        if(arr[k][y]==1){
            return false;
        }
    }
    int X=y,Y=x;
    while(Y>=0&&X>=0){
        if(arr[Y][X]==true){
            return false;
        }
        X--;
        Y--;
    }
    X=y,Y=x;
    while(Y>=0&&X<n){
        if(arr[Y][X]==true){
            return false;
        }
        X++;
        Y--;
    }
    return true;
}
bool nQueen(int **arr,int x,int n){
    if(x>=n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            nQueen(arr,x+1,n);
            arr[x][col]=0;      
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the size of arr:";
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    nQueen(arr,0,n);
}