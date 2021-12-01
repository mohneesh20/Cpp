#include <iostream>
#include<vector>
using namespace std;
void markUnsafe(int** grid,int m,int n){
    vector<int> x={1,0,-1,0};
    vector<int> y={0,1,0,-1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                for(int k=0;k<4;k++){
                    int Y=i+y[k];
                    int X=j+x[k];
                    if(Y>=0&&Y<m-1&&X>=0&&X<n-1){
                    grid[Y][X]=2;
                    }
                }
            }
        }
    }
}
int getDistance(int** grid,vector<vector<bool>> visited,int m,int n){
 for(int i=0;i<m;i++){
     int starting_value=grid[i][0];
     for(int j=0;j<m;j++){
         if()
     }
 }
}
int main() {
    int m,n;
    cin>>m>>n;
    int** grid=new int*[m];
    for(int i=0;i<m;i++){
        grid[i]=new int[n];
        for(int j=0;j<n;j++){
            grid[i][j]=1;
        }
    }
    grid[1][1]=0;
    grid[2][3]=0;
    grid[3][4]=0;
    grid[5][5]=0;
    grid[6][1]=0;
    grid[6][8]=0;
    grid[9][0]=0;
    grid[9][5]=0;
    grid[11][3]=0;
    markUnsafe(grid,m,n);
    vector<vector<bool>> visited(m);
    for(int i=0;i<m;i++){
        visited[i]=vector<bool>(n,false);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    getDistance(grid,visited,m,n);
}
