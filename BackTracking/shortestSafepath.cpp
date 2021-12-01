#include <iostream>
#include<vector>
using namespace std;
int minDist=INT32_MAX;
vector<int> x={1,0,-1,0};
vector<int> y={0,1,0,-1};
void markUnsafe(int** grid,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                for(int k=0;k<4;k++){
                    int Y=i+y[k];
                    int X=j+x[k];
                    if(Y>=0&&Y<m-1&&X>=0&&X<n-1){
                    grid[Y][X]=8;
                    }
                }
            }
        }
    }
}
void getDistance(int** grid,int m,int n,int sr,int sc,int dr,int dc,int counter,vector<vector<bool>> &visited){
    if(grid[sr][sc]!=1){
        return;
    }
    if(minDist==n-1){
        return;
    }
    if(sc==dc){
        if(minDist>counter){
            minDist=counter;
        }
        // cout<<counter<<endl;
        return;
    }
    counter++;
    for(int i=0;i<4;i++){
        int X=sc+x[i];
        int Y=sr+y[i];
        if(X>=0&&X<n&&Y>=0&&Y<m&&visited[Y][X]==false&&grid[Y][X]==1){
            visited[Y][X]=true;
            getDistance(grid,m,n,Y,X,dr,dc,counter,visited);
            visited[Y][X]=false;
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
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            // cout<<i<<":"<<0<<"  "<<j<<":"<<n-1<<endl;
            // getDistance(grid,m,n,i,0,j,n-1,0,visited);
            getDistance(grid,m,n,i,0,j,n-1,0,visited);
        }
    }
            cout<<"Distance:"<<minDist<<endl;
}
