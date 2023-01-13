#include<vector>
#include<iostream>
using namespace std;
int ans=0;
vector<int> X={1,0,-1,0};
vector<int> Y={0,1,0,-1};
bool isValid(vector<vector<int>> grid,int x,int y){
    bool flag=true;
    if(x<0||x>=grid[0].size()){
        flag=false;
    }
    if(y<0||y>=grid.size()){
        flag=false;
    }
    return flag;
}
void dfs(vector<vector<int>> grid,int walkables,int cnt,int y,int x,vector<vector<bool>> visited){
    if(grid[y][x]==2&&cnt==walkables){
        ans++;
        return;
    }
    visited[y][x]=true;
    for(int k=0;k<4;k++){
        int i=y+Y[k];
        int j=x+X[k];
        if(isValid(grid,j,i)&&(grid[i][j]==0||grid[i][j]==2)&&(visited[i][j]==false)){
            dfs(grid,walkables,cnt+1,i,j,visited);
        }
    }
}
void uniquePaths(vector<vector<int>> grid){
    int walkables=1;
    int x,y;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0){
                walkables++;
            }
            if(grid[i][j]==1){
                y=i;
                x=j;
            }
        }
    }
    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
    dfs(grid,walkables,0,y,x,visited);
}
int main()
{
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    uniquePaths(grid);     
    cout<<ans;
    return 0;
}
