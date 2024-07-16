#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> answer;
vector<int> x={1,0,-1,0};
vector<int> y={0,1,0,-1};
int cost=0;
void AllPath(int** mat,int m,int n,int counter,int row,int col,int dr,int dc,vector<vector<bool>> &visited){
    counter++;
    if(row==dr&&col==dc){
        counter--;
        if(cost<counter){
            cost=counter;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int X=col+x[i];
        int Y=row+y[i];
        if(X>=0&&X<n&&Y>=0&&Y<m&&visited[Y][X]==false&&mat[Y][X]==1){
        visited[row][col]=true;
        AllPath(mat,m,n,counter,Y,X,dr,dc,visited);
        visited[row][col]=false;
        }
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    int **mat=new int*[m];
    for(int i=0;i<m;i++){
        mat[i]=new int[n];
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            mat[i][j]=tmp;
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // 
    int dr,dc;
    cin>>dr>>dc;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    AllPath(mat,m,n,0,0,0,dr,dc,visited);
    cout<<"Maximum cost:"<<cost;
}