#include<iostream>
#include<vector>
using namespace std;
vector<int> x={2,2,-2,-2,-1,1,-1,1};
vector<int> y={-1,1,-1,1,2,2,-2,-2};
bool getPath(int n,int sr,int sc,int counter,vector<vector<bool>> visited,vector<vector<int>> &mat){
      
    // path.push_back(grid[sr][sc]);
    if(counter==n*n){
        return true;
    }
    for(int i=0;i<8;i++){
        int X=sr+x[i];
        int Y=sc+y[i];
        if(X>=0&&X<n&&Y>0&&Y<n&&visited[Y][X]==false){
            // cout<<Y<<" "<<X<<endl;
            visited[Y][X]=true;
            bool res=getPath(n,Y,X,counter+1,visited,mat);
            mat[Y][X]=counter;
            if(res){
                return true;
            }
            else{
            visited[Y][X]=false;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<vector<int>> mat(n,vector<int>(n,0));
    visited[0][0]=true;
    if(getPath(n,0,0,1,visited,mat)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"PATH NOT POSSIBLE";
    }
}