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
void dfs(vector<vector<int>> grid,int walkables,int cnt,int y,int x,vector<vector<bool>> visited,vector<vector<int>> pth){
    visited[y][x]=true;
    if(cnt==9){
        for(auto x:pth){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        cout<<"--------"<<endl;
        return;
    }
    // cout<<endl;
    if(grid[y][x]==2){
        // cout<<"count:"<<cnt<<endl;
        return;
    }
    for(int k=0;k<4;k++){
        int i=y+Y[k];
        int j=x+X[k];
        if(isValid(grid,j,i)&&(grid[i][j]==0||grid[i][j]==2)&&(visited[i][j]==false)){
            // cout<<i<<" "<<j<<" "<<cnt<<endl;
            pth.push_back({i,j,cnt+1});
            dfs(grid,walkables,cnt+1,i,j,visited,pth);
        }
    }
}
void uniquePaths(vector<vector<int>> grid){
    int walkables=0;
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
    dfs(grid,walkables,0,y,x,visited,{{y,x,0}});
}
int main()
{
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    uniquePaths(grid);     

    return 0;
}
