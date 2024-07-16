#include<iostream>
#include<vector>
using namespace std;
vector<int> x={0,-1,1,0};
vector<int> y={1,0,0,-1};
vector<string> output;
// void path(vector<vector<int>> grid,vector<vector<bool>> &visited,int sx,int sy,int n,string s){
//     visited[sy][sx]=true;
//     if(sy==(n-1)&&sx==(n-1)){
//         cout<<s<<endl;
//         // output.push_back(s);
//         return;
//     }
//     for(int i=0;i<4;i++){
//         int X=x[i]+sx;
//         int Y=y[i]+sy;
//         if(X<0||X==n){
//             continue;
//         }
//         if(Y<0||Y==n){
//             continue;
//         }
//         if(visited[Y][X]==false&&grid[Y][X]==1){
//             if(i==0){
//                 s=s+"D";
//             }
//             if(i==1){
//                 s=s+"L";
//             }
//             if(i==2){
//                 s=s+"R";
//             }
//             if(i==3){
//                 s=s+"U";
//             }
//             path(grid,visited,X,Y,n,s);
//             visited[Y][X]=false;
//         }
//     }
//     return;
// }
 void dfspath(int i, int j, string s, vector<vector<int>> &m, int n,vector<vector<bool>> &vis )
   {
       
       if(i == n-1 && j == n-1)
           {
               cout<<s<<endl;
               output.push_back(s);
               return;
           }
          
          
         if(i+1 <n && !vis[i+1][j] && m[i+1][j]==1){
           
           vis[i+1][j] = true;
           dfspath(i+1,j,s+"D",m,n,vis);
           vis[i+1][j] = false;
       }
       if(j-1 >=0 && !vis[i][j-1] && m[i][j-1]==1){
           
           vis[i][j-1] = true;
           dfspath(i,j-1,s+"L",m,n,vis);
           vis[i][j-1] = false;
       }
       
        if(j+1 <n && !vis[i][j+1] && m[i][j+1]==1){
           
           vis[i][j+1] = true;
           dfspath(i,j+1,s+"R",m,n,vis);
           vis[i][j+1] = false;
       }
       
       if(i-1 >=0 && !vis[i-1][j] && m[i-1][j]==1){
           
           vis[i-1][j] = true;
           dfspath(i-1,j,s+"U",m,n,vis);
           vis[i-1][j] = false;
       }
   }
void findPath(vector<vector<int>> grid,int n){
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    dfspath(0,0,"",grid,n,visited);
}
int main(){
    int N;
    cin>>N;
    vector<vector<int>> grid={
         {1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}
    };
    findPath(grid,N);
    cout<<output.size()<<endl;
    // for(auto x:output){
    //     cout<<x<<endl;
    // }
}