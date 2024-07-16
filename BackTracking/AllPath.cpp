#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> answer;
vector<int> x={1,0};
vector<int> y={0,1};
void AllPath(int** mat,int m,int n,vector<int> path,int row,int col){
    path.push_back(mat[row][col]);
    if(row==m-1&&col==n-1){
        answer.push_back(path);
        return;
    }
    for(int i=0;i<2;i++){
        int X=col+x[i];
        int Y=row+y[i];
        if(X<n&&Y<m){
        AllPath(mat,m,n,path,Y,X);
        }
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    int counter=1;
    int **mat=new int*[m];
    for(int i=0;i<m;i++){
        mat[i]=new int[n];
        for(int j=0;j<n;j++){
            mat[i][j]=counter;
            counter++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<int> path;
    AllPath(mat,m,n,path,0,0);
    for(auto path:answer){
        for(auto node:path){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}